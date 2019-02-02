#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDragEnterEvent>
#include <QMainWindow>
#include "playercontrols.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void dragEnterEvent(QDragEnterEvent *event);
    void open();
private:
    Ui::MainWindow *ui;
    PlayerControls *pc;

    // QWidget interface
protected:
    void dropEvent(QDropEvent *event);
};

#endif // MAINWINDOW_H
