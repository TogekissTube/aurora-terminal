#ifndef SHORTCUTS_H
#define SHORTCUTS_H

#include <QObject>
#include <QMainWindow>

class Shortcuts : public QObject {
    Q_OBJECT

public:
    explicit Shortcuts(QMainWindow *parent);

signals:
    void newTabRequested();
    void closeTabRequested();
    void aboutRequested();

private:
    QMainWindow *mainWindow;
    void setupShortcuts();
};

#endif // SHORTCUTS_H
