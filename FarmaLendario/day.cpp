#include "day.h"
#include "QVBoxLayout"

Day::Day(QWidget *parent,int number ,DAY day): MagicFrame(parent)
{
    this->day = day;
    this->number = number;
    QVBoxLayout *vL = new QVBoxLayout(this);
    vL->setAlignment(Qt::AlignCenter);
    vL->setContentsMargins(2,2,2,2);
    vL->setSpacing(2);
    for(int i=0;i< IN_LAST;i++){
        this->info[i] = new QLabel(this);
        this->info[i]->setObjectName("lb" +infoObjectName[i]);
        this->info[i]->setText(infoObjectName[i]);
        vL->addWidget(this->info[i]);

    }
    this->info[IN_NUMBER]->setFixedWidth(120);
    this->info[IN_NAME  ]->setFixedSize(120,25);
    this->info[IN_DIR   ]->setFixedSize(120,20);
    this->info[IN_TEL   ]->setFixedWidth(120);
    this->info[IN_NUMBER]->setAlignment(Qt::AlignLeft);
    this->info[IN_NAME  ]->setAlignment(Qt::AlignCenter);
    this->info[IN_DIR   ]->setAlignment(Qt::AlignCenter);
    this->info[IN_TEL   ]->setAlignment(Qt::AlignCenter);
    this->info[IN_NUMBER]->setText(QString::number(this->number));
    this->setFrameShape(QFrame::StyledPanel);
    this->setObjectName("dayFr");
    this->setProperty("current",false);
//    this->setMinimumSize(100,100);

}

FARMACIAS Day::getDeTurno() const
{
    return deTurno;
}

void Day::setDeTurno(FARMACIAS newDeTurno)
{
    deTurno = newDeTurno;
    this->info[IN_NAME]->setText(farmNombre[deTurno].toUpper());
    this->info[IN_DIR]->setText(farmDireccion[deTurno]);
    this->info[IN_TEL]->setText(farmTelefono[deTurno]);
}

int Day::getNumber() const
{
    return number;
}

void Day::setNumber(int newNumber)
{
    number = newNumber;
}



