#ifndef SELECTOR_H
#define SELECTOR_H

#include <QObject>
#include <QFrame>
#include <QPushButton>
#include <QHBoxLayout>
#include <Qlabel>

#include "templates.h"


class FarmBtn : public MagicFrame{
    Q_OBJECT

public:
    FarmBtn(QWidget *parent = nullptr, FARMACIAS farm = FARM_LAST);
    FARMACIAS farm;
public slots:
    void onClicked();
signals:
    void farmClicked(FARMACIAS farm);

};

class MonthButton : public MagicFrame{
    Q_OBJECT
    MONTH month;
public:
    MonthButton(QWidget *parent = nullptr, MONTH month = MO_LAST);
public slots:
    void onClicked();
signals:
    void monthClicked(MONTH month);
};

class Selector: public QFrame
{
    Q_OBJECT

public:
    Selector(QWidget *parent = nullptr);

    QVector<FarmBtn*> farmsBtns;
    QVector<MonthButton*> monthBtns;
    QVBoxLayout *vl;
    void showOptions(FARMACIAS first);
    void showOptions(MONTH current, int year);
    void hideAll();

    QLabel *lbText;
public slots:
    void onSaveClicked();
signals:
    void farmClicked(FARMACIAS farmacia);
    void monthClicked(MONTH mes, int year);
    void saveThis();


};



#endif // SELECTOR_H
