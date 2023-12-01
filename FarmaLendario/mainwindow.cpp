#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGridLayout>
#include <QFrame>
#include <QLabel>
#include <QDateTime>
#include <QResizeEvent>
#include <QFontDatabase>
#include <QFileDialog>
#include <QProcessEnvironment>
#include <QMenuBar>
#include "config.h"
static const QString calendarTxt[FarmaLendario::CO_LAST]{
    "Ir al calendario",
    "Guardar"
};
static const QString avisoTxt[FarmaLendario::AO_LAST]{
    "Ir al calendario",
    "Guardar"
};
FarmaLendario::FarmaLendario(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->config = new Config();

    this->setWindowTitle(this->config->getAppName() + " v" + this->config->getVersion());
    this->setWindowIcon(QIcon(":/images/logo"));
    this->centralWidget()->setObjectName("generalWid");
    this->statusBar()->setVisible(false);

    this->select = new Selector(this);
    connect(this->select,&Selector::farmClicked,this,&FarmaLendario::onOptionDayClicked);
    connect(this->select,&Selector::monthClicked,this,&FarmaLendario::onOptionMonthClicked);
    this->mes = new Month(this,(MONTH)(QDateTime::currentDateTime().toString("MM").toInt()),QDateTime::currentDateTime().toString("yyyy").toInt());
    connect(this->mes,&Month::dayClicked,this,&FarmaLendario::onDayClicked);
    connect(this->mes,&Month::monthClicked,this,&FarmaLendario::onMonthClicked);

    int aux= 0;
    for(int i = 0;i< this->mes->getNumberOfDays();i++){
        this->mes->setDeTurno(i,FARMACIAS(aux));
        if(aux == 11){
            aux=0;
        }else aux++;
    }

    QHBoxLayout *hL = new QHBoxLayout(this);
    hL->addWidget(this->mes);
    hL->addWidget(this->select);
    hL->setContentsMargins(0,0,0,0);
    hL->setSpacing(1);
    QMenuBar *mb = new QMenuBar(this);
    QMenu *calendario = new QMenu("Calendario",mb);

    for(int i = 0; i< CO_LAST; i++){
        QAction *aux = new QAction(calendarTxt[i],mb);
        this->calendarAct.append(aux);
        aux->setEnabled(false);
        calendario->addAction(aux);
    }
    mb->addMenu(calendario);
    QMenu *avisos = new QMenu("Avisos",mb);
    for(int i = 0; i< AO_LAST; i++){
        QAction *aux = new QAction(avisoTxt[i],mb);
        this->avisosAct.append(aux);
        aux->setEnabled(false);
        avisos->addAction(aux);
    }
    this->calendarAct.at(CO_GUARDAR)->setEnabled(true);
    mb->addMenu(avisos);
    connect(mb,&QMenuBar::triggered,this,&FarmaLendario::onActionTriggered);
    this->setMenuBar(mb);
    this->centralWidget()->setLayout(hL);

    QCoreApplication::setAttribute(Qt::AA_UseStyleSheetPropagationInWidgetStyles,true);
    int loadedFontID = QFontDatabase::addApplicationFont(":/fonts/tungsten.ttf");
    QStringList loadedFontFamilies = QFontDatabase::applicationFontFamilies(loadedFontID);
    qDebug() << loadedFontFamilies;
    qApp->setStyleSheet(this->config->getStyles());


}

FarmaLendario::~FarmaLendario()
{
    delete ui;
}

void FarmaLendario::saveAviso()
{

}

void FarmaLendario::onDayClicked(Day *day)
{
//    qApp->setStyleSheet(this->config->getStyles());
    if(day->getNumber() < 0){
        this->select->hideAll();
        return;
    }
    qDebug() << "clickedMAINWIN" << day->getNumber();
    this->select->showOptions(day->getDeTurno());

}

void FarmaLendario::onMonthClicked(Month *month)
{
    this->select->showOptions(month->getMonth(), month->getYear());
}

void FarmaLendario::onOptionDayClicked(FARMACIAS farm)
{
    this->mes->setDeTurnoDaySelected(farm);
}

void FarmaLendario::onOptionMonthClicked(MONTH month, int year)
{
    this->mes->setYear(year);
    this->mes->setMonth(month);
}

void FarmaLendario::saveCalendar()
{
    QSize size = this->mes->size();
    this->mes->setFixedSize(900,700);
    QPixmap pixmap(this->mes->size());

    this->mes->render(&pixmap);
    this->mes->setFixedSize(size);
    qDebug() << "saving" << qgetenv("CSIDL_COMMON_DESKTOPDIRECTORY");
    QString filename= QFileDialog::getSaveFileName(this, "Guardar como",qgetenv("USERPROFILE"),"Imagenes (*.png *.xpm *.jpg)");
    pixmap.save(filename);
}

void FarmaLendario::onActionTriggered(QAction *action)
{
        for(QAction *calendar:this->calendarAct){
            if(action == calendar){
            switch((CalendarOp)this->calendarAct.indexOf(calendar)){
                case CO_CALENDAR:
                case CO_LAST:
                        break;
                    case CO_GUARDAR:
                        this->select->hideAll();
                        this->saveCalendar();
                    }
                }
        }
        for(QAction *aviso:this->avisosAct ){
                if(action == aviso){
                    switch((AvisosOp)this->avisosAct.indexOf(aviso)){
                    case FarmaLendario::AO_AVISOS:
                    case AO_LAST:
                        break;
                    case AO_GUARDAR:
                        this->saveAviso();
                    }
                }
        }
        qDebug() << action->text();
}

void FarmaLendario::resizeEvent(QResizeEvent *pQEvent)
{
    qDebug() << QString("width:%1 height:%2").arg(pQEvent->size().width()).arg(pQEvent->size().height());
    pQEvent->accept();
}

