#include "include/mainwindow.h"
#include "include/terminalwidget.h"
#include "include/about.h"

#include <QMenuBar>
#include <QAction>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), tabWidget(new QTabWidget(this)), shortcuts(new Shortcuts(this)) {
    setCentralWidget(tabWidget);

    // Configuración del menú
    auto *menuBar = new QMenuBar(this);
    auto *fileMenu = menuBar->addMenu("&Archivo");

    auto *newTabAction = new QAction("Nueva Pestaña", this);
    auto *closeTabAction = new QAction("Cerrar Pestaña", this);
    auto *aboutAction = new QAction("Acerca de", this);

    fileMenu->addAction(newTabAction);
    fileMenu->addAction(closeTabAction);
    fileMenu->addSeparator();
    fileMenu->addAction(aboutAction);

    connect(newTabAction, &QAction::triggered, this, &MainWindow::newTab);
    connect(closeTabAction, &QAction::triggered, this, &MainWindow::closeCurrentTab);
    connect(aboutAction, &QAction::triggered, this, &MainWindow::showAbout);

    setMenuBar(menuBar);

    // Configuración de atajos de teclado
    connect(shortcuts, &Shortcuts::newTabRequested, this, &MainWindow::newTab);
    connect(shortcuts, &Shortcuts::closeTabRequested, this, &MainWindow::closeCurrentTab);
    connect(shortcuts, &Shortcuts::aboutRequested, this, &MainWindow::showAbout);

    // Crear la primera pestaña
    newTab();
}

void MainWindow::newTab() {
    auto *terminal = new TerminalWidget(this);
    int index = tabWidget->addTab(terminal, "Terminal");
    tabWidget->setCurrentIndex(index);
}

void MainWindow::closeCurrentTab() {
    int currentIndex = tabWidget->currentIndex();
    if (currentIndex != -1) {
        tabWidget->removeTab(currentIndex);
    }
}

void MainWindow::showAbout() {
    About aboutDialog(this);
    aboutDialog.exec();
}
