#ifndef MONTH_H
#define MONTH_H

#include <QObject>
#include "day.h"

class Month : public QFrame
{
    Q_OBJECT
public:
    enum MONTH{
        MO_JANUARY,
        MO_FEBRUARY,
        MO_MARCH,
        MO_APRIL,
        MO_MAY,
        MO_JUNE,
        MO_JULY,
        MO_AUGUST,
        MO_SEPTEMBER,
        MO_OCTOBER,
        MO_NOVEMBER,
        MO_DECEMBER,

        MO_LAST
    };

    explicit Month(QFrame *parent = nullptr, MONTH month = MO_LAST, int startDay = 0,int year = 2023);
    //    MES mes;
    int getNumberOfDays() const;

    void setDeTurno(int day, FARMACIAS deTurno);

    int getStartDay() const;
    void setStartDay(int newStartDay);

    int getYear() const;
    void setYear(int newYear);

    MONTH getMonth() const;
    void setMonth(MONTH newMonth);

    void resize(const QSize &size);


private:
    MONTH month;
    QList<Day*> days;
    QLabel *lbName;
    QFrame *daysFrame;
    int startDay;
    int numberOfDays;
    int weeks = 1;
    int year;
    void setDays();
    void updateLayout();
signals:

};

#endif // MONTH_H
