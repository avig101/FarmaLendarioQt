#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "month.h"
#include "config.h"
#include "selector.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class FarmaLendario : public QMainWindow
{
    Q_OBJECT

public:
    enum CalendarOp{
        CO_CALENDAR,
        CO_GUARDAR,

        CO_LAST
    }calendarOp;
    enum AvisosOp{
        AO_AVISOS,
        AO_GUARDAR,

        AO_LAST
    }avisosOp;

    FarmaLendario(QWidget *parent = nullptr);
    ~FarmaLendario();

    void saveAviso();
    void saveCalendar();

public slots :
    void onDayClicked(Day *day);
    void onMonthClicked(Month *month);
    void onOptionDayClicked(FARMACIAS farm);
    void onOptionMonthClicked(MONTH month, int year);
    void onActionTriggered(QAction *action);
protected:
    virtual void resizeEvent(QResizeEvent *pQEvent);

private:
    Ui::MainWindow *ui;
    Month *mes;
    Selector *select;
    Config *config;

    QVector<QAction*> calendarAct;
    QVector<QAction*> avisosAct;

};
#endif // MAINWINDOW_H
