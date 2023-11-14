#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "month.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
protected:
    virtual void resizeEvent(QResizeEvent *pQEvent);

private:
    Ui::MainWindow *ui;
    Month *mes;
};
#endif // MAINWINDOW_H
