#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTabWidget>
#include "shortcuts.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

private slots:
    void newTab();
    void closeCurrentTab();
    void showAbout();

private:
    QTabWidget *tabWidget;
    Shortcuts *shortcuts;
};

#endif // MAINWINDOW_H
