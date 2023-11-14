#include "day.h"
#include "QVBoxLayout"



Day::Day(QWidget *parent,int number ,DAY day)
{
    this->setParent(parent);
    this->day = day;
    this->number = number;
    QVBoxLayout *vL = new QVBoxLayout(this);
    vL->setAlignment(Qt::AlignCenter);
    for(int i=0;i< IN_LAST;i++){
        this->info[i] = new QLabel(this);
        this->info[i]->setObjectName(infoObjectName[i]+"Label");
        this->info[i]->setText(infoObjectName[i]);
        this->info[i]->setFont(QFont("Tungsten Semibold",20,250));
        vL->addWidget(this->info[i]);

    }
    this->info[IN_NUMBER]->setFixedSize(120,30);
    this->info[IN_NAME  ]->setFixedSize(120,40);
    this->info[IN_DIR   ]->setFixedSize(120,40);
    this->info[IN_TEL   ]->setFixedSize(120,40);
    this->info[IN_NUMBER]->setAlignment(Qt::AlignLeft);
    this->info[IN_NAME  ]->setAlignment(Qt::AlignCenter);
    this->info[IN_DIR   ]->setAlignment(Qt::AlignCenter);
    this->info[IN_TEL   ]->setAlignment(Qt::AlignCenter);
    this->info[IN_NUMBER]->setText(QString::number(this->number));
    this->setFrameShape(QFrame::Panel);

}

FARMACIAS Day::getDeTurno() const
{
    return deTurno;
}

void Day::setDeTurno(FARMACIAS newDeTurno)
{
    deTurno = newDeTurno;
    this->info[IN_NAME]->setText(farmNombre[deTurno]);
    this->info[IN_DIR]->setText(farmDireccion[deTurno]);
    this->info[IN_TEL]->setText(farmTelefono[deTurno]);
}
