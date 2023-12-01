#include "selector.h"
#include <QStyle>

Selector::Selector(QWidget *parent)
{
    this->setParent(parent);
    this->setMinimumSize(300,500);
    this->setFrameStyle(QFrame::StyledPanel);
    this->setObjectName("selectFr");
    this->vl = new QVBoxLayout;
    this->vl->setContentsMargins(1,1,1,1);
    this->vl->setSpacing(1);

    this->lbText = new QLabel(this);
    this->lbText->setObjectName("lbFarmacia");
    this->lbText->setAlignment(Qt::AlignCenter);
    this->lbText->setFixedHeight(30);

    QFrame *vlFrame = new QFrame(this);
    QVBoxLayout *vlGeneral = new QVBoxLayout;
    vlFrame->setLayout(this->vl);

    vlGeneral->addWidget(this->lbText,Qt::AlignTop | Qt::AlignHCenter);
    vlGeneral->addWidget(vlFrame);
    vlGeneral->setContentsMargins(3,3,3,3);
    vlGeneral->setSpacing(3);

    this->setLayout(vlGeneral);
}

void Selector::showOptions(FARMACIAS first)
{
    Q_UNUSED(first);
    this->hideAll();
    this->lbText->setText("Seleccione una farmacia");
    this->lbText->setVisible(true);
    for(int i = 0;i< FARMACIAS::FARM_LAST;i++){
        FarmBtn *aux = new FarmBtn(this,(FARMACIAS)i);
        if(/*i == first*/0){
            this->farmsBtns.prepend(aux);
            aux->setCurrent(true);
            this->vl->insertWidget(0,aux);
        }else{
            this->farmsBtns.append(aux);
            this->vl->addWidget(aux);
        }
        aux->setFixedHeight(45);
        aux->setContentsMargins(0,0,0,0);
        connect(aux,&FarmBtn::farmClicked,this,[=](FARMACIAS farm){
            FarmBtn *fr = qobject_cast<FarmBtn*>(sender());
            for(FarmBtn* btn:farmsBtns){
                btn->setCurrent(btn == fr);
            }
            emit farmClicked(farm);
        });

    }
}

void Selector::showOptions(MONTH current,int year)
{
    Q_UNUSED(year);
    Q_UNUSED(current);

    this->hideAll();
    this->lbText->setText("Seleccione un mes");
    this->lbText->setVisible(true);
    for(int i = 0;i< MONTH::MO_LAST;i++){
        MonthButton *aux = new MonthButton(this,(MONTH)i);
        if(/*i == current*/0){
            this->monthBtns.prepend(aux);
            aux->setCurrent(true);
            this->vl->insertWidget(0,aux);
        }else{
            this->monthBtns.append(aux);
            this->vl->addWidget(aux);
        }
        aux->setFixedHeight(45);
        aux->setContentsMargins(0,0,0,0);
        connect(aux,&MonthButton::monthClicked,this,[=](MONTH month){
            emit monthClicked(month,2023);
        });

    }
}

void Selector::hideAll()
{
    for(FarmBtn *bt:farmsBtns){
        this->vl->removeWidget(bt);
    }
    qDeleteAll(this->farmsBtns);
    this->farmsBtns.clear();

    for(MonthButton *bt:monthBtns){
        this->vl->removeWidget(bt);
    }
    qDeleteAll(this->monthBtns);
    this->monthBtns.clear();
    this->lbText->setVisible(false);


}

void Selector::onSaveClicked()
{
    emit saveThis();
}

FarmBtn::FarmBtn(QWidget *parent, FARMACIAS farm) : MagicFrame(parent)
{
    this->farm = farm;
    QHBoxLayout *farmHb = new QHBoxLayout;
    QLabel *name = new QLabel(farmNombre[farm],this);
    name->setObjectName("lbSelect");
    farmHb->addWidget(name);
    this->setObjectName("selectBttnFr");
    connect(this,&FarmBtn::clicked,this,&FarmBtn::onClicked);

    this->setLayout(farmHb);

}

void FarmBtn::onClicked()
{
    emit farmClicked(this->farm);
}


MonthButton::MonthButton(QWidget *parent, MONTH month) : MagicFrame(parent)
{
    this->month = month;
    QHBoxLayout *monthHb = new QHBoxLayout;
    QLabel *name = new QLabel(mesTxt[month],this);
    name->setObjectName("lbSelect");
    monthHb->addWidget(name);
    this->setObjectName("selectBttnFr");
    connect(this,&MonthButton::clicked,this,&MonthButton::onClicked);

    this->setLayout(monthHb);
}

void MonthButton::onClicked()
{
    emit monthClicked(this->month);
}
