#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGridLayout>
#include <QFrame>
#include <QLabel>
#include <QDateTime>
#include <QResizeEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("FarmaLendario v0.1");
    this->setWindowIcon(QIcon(":/images/logo"));
    this->mes = new Month(qobject_cast<QFrame*>(this),(Month::MONTH)QDateTime::currentDateTime().toString("MM").toInt(),3);
    int aux= 0;
    for(int i = 0;i< this->mes->getNumberOfDays();i++){
        this->mes->setDeTurno(i,FARMACIAS(aux));
        if(aux == 11){
            aux=0;
        }else aux++;
    }
    this->setCentralWidget(this->mes);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent *pQEvent)
{
    qDebug() << QString("width:%1 height:%2").arg(pQEvent->size().width()).arg(pQEvent->size().height());
    QPixmap bkgnd(":/images/background");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);
    pQEvent->accept();
}

