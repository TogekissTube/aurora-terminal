#include "include/terminalwidget.h"
#include <QVBoxLayout>
#include <QTextCursor>
#include <QRegularExpression>

TerminalWidget::TerminalWidget(QWidget *parent)
    : QWidget(parent), process(new QProcess(this)) {
    auto *layout = new QVBoxLayout(this);

    // Configurar la salida de la terminal
    terminalOutput = new QPlainTextEdit(this);
    terminalOutput->setReadOnly(true);
    terminalOutput->setStyleSheet(
        "background-color: #232323; color: #ffffff; font-family: monospace; font-size: 12px;"
    );

    // Configurar la entrada de la terminal
    terminalInput = new QLineEdit(this);
    terminalInput->setStyleSheet(
        "background-color: #1e1e1e; color: #ffffff; font-family: monospace; font-size: 12px;"
    );

    layout->addWidget(terminalOutput);
    layout->addWidget(terminalInput);
    setLayout(layout);

    // Configurar el ambiente del proceso
    QProcessEnvironment env = QProcessEnvironment::systemEnvironment();
    env.insert("TERM", "xterm-256color");  // Emular terminal típica
    env.insert("PS1", "\\$ ");            // Prompt simple
    process->setProcessEnvironment(env);

    // Configurar el programa y argumentos
    process->setProgram("script");
    process->setArguments({"-q", "/dev/null", "/bin/bash", "-i"});

    // Configurar para que `stdin` se dirija correctamente al proceso
    process->setProcessChannelMode(QProcess::ForwardedChannels);

    // Iniciar el proceso
    process->start();

    // Conexiones
    connect(terminalInput, &QLineEdit::returnPressed, this, &TerminalWidget::sendCommand);
    connect(process, &QProcess::readyReadStandardOutput, this, &TerminalWidget::readOutput);
    connect(process, &QProcess::readyReadStandardError, this, &TerminalWidget::readError);
}

void TerminalWidget::sendCommand() {
    QString command = terminalInput->text();
    if (!command.isEmpty()) {
        terminalOutput->appendPlainText("$ " + command);  // Mostrar el comando en la salida
        process->write((command + "\n").toUtf8());        // Enviar el comando a bash
        terminalInput->clear();
    }
}

void TerminalWidget::readOutput() {
    QString output = process->readAllStandardOutput();
    terminalOutput->appendPlainText(output);
}

void TerminalWidget::readError() {
    QString error = process->readAllStandardError();
    terminalOutput->appendPlainText("[Error] " + error);
}

