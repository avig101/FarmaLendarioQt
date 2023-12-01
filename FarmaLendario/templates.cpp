#include "templates.h"
#include <QStyle>

MagicFrame::MagicFrame(QWidget *parent): QFrame(parent)
{
    this->setProperty("onFocus",false);
    this->setProperty("current",false);
}
bool MagicFrame::isCurrent()
{
    return current;
}

void MagicFrame::setCurrent(bool isCurrent)
{

    if(isCurrent != this->current){
        qDebug() << "currentChanged" << isCurrent;
        this->current = isCurrent;
        emit currentSig(isCurrent);
        this->setProperty("current",isCurrent);
        this->setProperty("onFocus",isCurrent);
        this->style()->unpolish(this);
        this->style()->polish(this);
    }

}

void MagicFrame::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "clicked";
    emit clicked();
    event->accept();
}

void MagicFrame::enterEvent(QEnterEvent *event)
{
    if(!this->property("current").toBool() && this->isEnabled()){
        this->setProperty("onFocus",true);
        this->style()->unpolish(this);
        this->style()->polish(this);
    }

    event->accept();
}

void MagicFrame::leaveEvent(QEvent *event)
{
    if(!this->property("current").toBool()){
        this->setProperty("onFocus",false);
        this->style()->unpolish(this);
        this->style()->polish(this);
    }

    event->accept();
}
