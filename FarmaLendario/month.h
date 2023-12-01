#ifndef MONTH_H
#define MONTH_H

#include <QObject>
#include <QVBoxLayout>
#include <QGridLayout>
#include "day.h"


class clickableLb :public QLabel{
    Q_OBJECT
public:
    explicit clickableLb(QWidget *parent = nullptr);
    explicit clickableLb(const QString &text = nullptr,QWidget *parent = nullptr);

public slots:
    void mousePressEvent(QMouseEvent *event);
signals:
    void clicked();
};
class clickableFr :public QLabel{
    Q_OBJECT
public:
    explicit clickableFr(QWidget *parent = nullptr);

public slots:
    void mousePressEvent(QMouseEvent *event);
signals:
    void clicked();
};

class Month : public QFrame
{
    Q_OBJECT
public:
    explicit Month(QWidget *parent = nullptr, MONTH month = MO_LAST, int year = 2023);
    //    MES mes;
    int getNumberOfDays() const;

    void setDeTurno(int day, FARMACIAS deTurno);
    void setDeTurnoDaySelected(FARMACIAS deTurno);

    int getStartDay() const;
    void setStartDay(int newStartDay);

    int getYear() const;
    void setYear(int newYear);

    MONTH getMonth() const;
    void setMonth(MONTH newMonth);

    void resize(const QSize &size);

    void paintEvent(QPaintEvent *e);

private slots:
    void onDayClicked();
private:
    MONTH month;
    QList<Day*> days;
    QList<QFrame*> fillers;

    clickableLb *lbName;
    QFrame *daysFrame;
    QVBoxLayout *vL;
    QGridLayout *gL ;
    int currentDayClicked = 0;
    int startDay;
    int numberOfDays;
    int weeks = 1;
    int year;
    void setDays();
    void updateLayout();
signals:
    void dayClicked(Day *day);
    void monthClicked(Month *month);


};

#endif // MONTH_H
