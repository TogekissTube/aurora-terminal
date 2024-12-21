#include "include/mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MainWindow mainWindow;
    mainWindow.setWindowTitle("Terminal");
    mainWindow.resize(800, 600);
    mainWindow.show();

    return app.exec();
}
