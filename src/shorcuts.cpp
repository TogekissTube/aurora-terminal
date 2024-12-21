#include "include/shortcuts.h"
#include <QShortcut>

Shortcuts::Shortcuts(QMainWindow *parent) : QObject(parent), mainWindow(parent) {
    setupShortcuts();
}

void Shortcuts::setupShortcuts() {
    auto *newTabShortcut = new QShortcut(QKeySequence("Ctrl+T"), mainWindow);
    connect(newTabShortcut, &QShortcut::activated, this, &Shortcuts::newTabRequested);

    auto *closeTabShortcut = new QShortcut(QKeySequence("Ctrl+W"), mainWindow);
    connect(closeTabShortcut, &QShortcut::activated, this, &Shortcuts::closeTabRequested);

    auto *aboutShortcut = new QShortcut(QKeySequence("Ctrl+I"), mainWindow);
    connect(aboutShortcut, &QShortcut::activated, this, &Shortcuts::aboutRequested);
}
