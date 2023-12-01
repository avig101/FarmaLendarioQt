#include "month.h"

#include <QDate>
#include <QPainter>


Month::Month(QWidget *parent, MONTH month, int year)
{
    this->setParent(parent);
    this->month = month;
    this->year = year;

    this->lbName = new clickableLb(this);
    this->lbName->setObjectName("lbMesAnio");
    this->lbName->setFixedHeight(30);
    connect(this->lbName,&clickableLb::clicked,this,[=]{
        emit monthClicked(this);
    });
    this->vL = new QVBoxLayout(this);
    this->vL->setAlignment(Qt::AlignCenter);
    this->vL->setSpacing(0);
    this->gL = new QGridLayout(this);
    this->gL->setContentsMargins(2,2,2,2);
    this->gL->setSpacing(2);
    this->gL->setObjectName("gridMonth");
    // Dias de la semana
    for(int i=0;i<DA_LAST;i++){
        clickableLb *ql = new clickableLb(dayTxt[i].toUpper(),this);
        ql->setAlignment(Qt::AlignCenter);
        ql->setObjectName("lbDiaSemana");
        gL->addWidget(ql,0,i);
    }
    this->daysFrame = new QFrame(this);
    this->daysFrame->setLayout(gL);

    vL->addWidget(this->lbName);
    vL->addWidget(this->daysFrame);
    vL->setContentsMargins(2,2,2,2);
    vL->setSpacing(0);
    this->setObjectName("generalFr");
    this->setFrameShape(QFrame::StyledPanel);
    this->setLayout(vL);


    this->setDays();


//    this->setMinimumSize(1200,900);

}

int Month::getNumberOfDays() const
{
    return numberOfDays;
}


void Month::setDeTurno(int day, FARMACIAS deTurno)
{
    this->days.at(day)->setDeTurno(deTurno);
}

void Month::setDeTurnoDaySelected(FARMACIAS deTurno)
{
    int day = this->currentDayClicked -1;

    if(day <0){
        return;
    }
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

MONTH Month::getMonth() const
{
    return this->month;
}

void Month::setMonth(MONTH newMonth)
{
    month = newMonth;
    this->setDays();
}

void Month::resize(const QSize &size)
{

    this->lbName->setFixedSize(size.width(),(size.height()*10)/100);
    this->daysFrame->setFixedSize(size.width(),(size.height()*90)/100);

}

void Month::setDays()
{
    for(Day *day:days){
        this->gL->removeWidget(day);
    }
    qDeleteAll(this->days);
    this->days.clear();
    qDebug() << "year"<<this->year << "month" << this->month;
    if((int)this->month == 1){
        if((this->year % 4 == 0 && this->year % 100 != 0) || (this-year % 400 == 0)){
            this->numberOfDays = 29;
        }else this->numberOfDays = 28;
    }else if(this->month<7){
        if((int)this->month %2 == 0){
            this->numberOfDays = 31;
        }else this->numberOfDays = 30;
    }else if((int)this->month %2 == 0){
        this->numberOfDays = 30;
    }else this->numberOfDays = 31;

    QDate firstDay(this->year, (int)(this->month) +1, 1);
    this->startDay = firstDay.dayOfWeek()%7;
    int aux = startDay;
    for(int i = 0; i<this->numberOfDays;i++){
        Day *day = new Day(this,i+1, (DAY)aux);
        connect(day,&Day::clicked,this,&Month::onDayClicked);
        this->days.append(day);
        if(aux == 6){
            weeks++;
            aux = 0;
        }else aux++;
    }
    this->updateLayout();


}

void Month::updateLayout()
{

    for(QFrame *fill:fillers){
        this->gL->removeWidget(fill);
    }
    qDeleteAll(fillers);
    fillers.clear();

    // Dia a dia
    int dayOfWeek = startDay;
    int week = 1;
    // Relleno
    for(int i = 0; i<dayOfWeek;i++){
        clickableFr *fr = new clickableFr(this);
        connect(fr,&clickableFr::clicked,this,[=]{
            qDebug() << "clickedDay" << -1;
            for(Day* day:this->days){
                day->setCurrent(false);
            }
            emit dayClicked(new Day(this,-1,DA_LAST));
        });
        fr->setFrameShape(QFrame::StyledPanel);
        fr->setObjectName("generalFr");
        fillers.append(fr);
        gL->addWidget(fr,week,i);

    }
    //Info
    for(int i = 0; i<this->numberOfDays;i++){
        gL->addWidget(this->days.at(i),week,dayOfWeek);
        if(dayOfWeek == 6){
            week++;
            dayOfWeek = 0;
        }else dayOfWeek++;

    }
    // Relleno
    if(dayOfWeek >0){
        for(int i = dayOfWeek; i<7;i++){
            clickableFr *fr = new clickableFr(this);
            connect(fr,&clickableFr::clicked,this,[=]{
                qDebug() << "clickedDay" << -1;
                for(Day* day:this->days){
                    day->setCurrent(false);
                }
                emit dayClicked(new Day(this,-1,DA_LAST));
            });
            fr->setFrameShape(QFrame::StyledPanel);
            fr->setObjectName("generalFr");
            fillers.append(fr);
            gL->addWidget(fr,week,i);

        }
    }

    this->lbName->setText(QString("TURNOS %1 %2").arg(mesTxt[this->month].toUpper(),QString::number(this->year)));
    this->lbName->setAlignment(Qt::AlignCenter);

}
void Month::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    painter.drawImage(this->rect().marginsRemoved(QMargins(2,2,2,2)),QImage(":/images/background"));

    QFrame::paintEvent(e);

}

void Month::onDayClicked()
{

    QObject *send = sender();
    Day *dayClicked = qobject_cast<Day*>(send);

    this->currentDayClicked = -1;
    for(Day* day:this->days){
        if(day == dayClicked){
            day->setCurrent(true);
            currentDayClicked = day->getNumber();
            qDebug() << "clickedDay" << currentDayClicked;
        }else day->setCurrent(false);
    }

    emit this->dayClicked(dayClicked);


}

clickableLb::clickableLb(QWidget *parent) : QLabel(parent)
{

}

clickableLb::clickableLb(const QString &text,QWidget *parent):QLabel(text,parent)
{

}

void clickableLb::mousePressEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    emit clicked();
}

clickableFr::clickableFr(QWidget *parent) : QLabel(parent)
{

}

void clickableFr::mousePressEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    emit clicked();
}
