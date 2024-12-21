#ifndef TERMINALWIDGET_H
#define TERMINALWIDGET_H

#include <QWidget>
#include <QPlainTextEdit>
#include <QLineEdit>
#include <QProcess>

class TerminalWidget : public QWidget {
    Q_OBJECT

public:
    explicit TerminalWidget(QWidget *parent = nullptr);

private slots:
    void sendCommand();
    void readOutput();
    void readError();

private:
    QPlainTextEdit *terminalOutput;
    QLineEdit *terminalInput;
    QProcess *process;
};

#endif // TERMINALWIDGET_H
