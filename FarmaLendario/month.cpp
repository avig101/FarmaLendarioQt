#include "month.h"
#include <QVBoxLayout>
#include <QGridLayout>
static const QString mesTxt[Month::MO_LAST]{
    "Enero",
    "Febrero",
    "Marzo",
    "Abril",
    "Mayo",
    "Junio",
    "Julio",
    "Agosto",
    "Septiembre",
    "Octubre",
    "Noviembre",
    "Diciembre"
};


Month::Month(QFrame *parent, MONTH month, int startDay,int year)
{
    this->setParent(parent);
    this->month = month;
    this->year = year;
    this->startDay = startDay;
    this->setDays();

    this->lbName = new QLabel(this);

    this->updateLayout();
}

int Month::getNumberOfDays() const
{
    return numberOfDays;
}


void Month::setDeTurno(int day, FARMACIAS deTurno)
{
    this->days.at(day)->setDeTurno(deTurno);
}

int Month::getStartDay() const
{
    return startDay;
}

void Month::setStartDay(int newStartDay)
{
    startDay = newStartDay;
}

int Month::getYear() const
{
    return year;
}

void Month::setYear(int newYear)
{
    year = newYear;
}

Month::MONTH Month::getMonth() const
{
    return this->month;
}

void Month::setMonth(MONTH newMonth)
{
    month = newMonth;
}

void Month::resize(const QSize &size)
{

    this->lbName->setFixedSize(size.width(),(size.height()*10)/100);
    this->daysFrame->setFixedSize(size.width(),(size.height()*90)/100);
}

void Month::setDays()
{
    qDeleteAll(this->days);
    this->days.clear();
    if((int)this->month == 1){
        if((this->year % 4 == 0 && this->year % 100 != 0) || (this-year % 400 == 0)){
            this->numberOfDays = 29;
        }else this->numberOfDays = 28;
    }else if((int)this->month %2 == 0){
        this->numberOfDays = 31;
    }else this->numberOfDays = 30;

    int aux = startDay;
    for(int i = 0; i<this->numberOfDays;i++){
        Day *day = new Day(this,i+1, (Day::DAY)aux);
        this->days.append(day);
        if(aux == 6){
            weeks++;
            aux = 0;
        }else aux++;
    }

}

void Month::updateLayout()
{

    QVBoxLayout *vL = new QVBoxLayout(this);
    QGridLayout *gL = new QGridLayout(this);
    this->daysFrame = new QFrame(this);

    int dayOfWeek = startDay;
    for(int i=0;i<Day::DA_LAST;i++){
        QLabel *ql = new QLabel(dayTxt[i].toUpper(),this);
        ql->setAlignment(Qt::AlignCenter);
        gL->addWidget(ql,0,i);
    }
    int week = 1;
    for(int i = 0; i<this->numberOfDays;i++){
        gL->addWidget(this->days.at(i),week,dayOfWeek);
        if(dayOfWeek == 6){
            week++;
            dayOfWeek = 0;
        }else dayOfWeek++;
    }

    this->lbName->setText(QString("TURNOS %1 %2").arg(mesTxt[this->month].toUpper(),QString::number(this->year)));
    this->lbName->setAlignment(Qt::AlignCenter);
    this->daysFrame->setLayout(gL);

    vL->addWidget(this->lbName);
    vL->addWidget(this->daysFrame);
    this->setFrameShape(QFrame::Panel);
    this->setLayout(vL);
}
