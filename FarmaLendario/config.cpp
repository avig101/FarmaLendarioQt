#include "config.h"
#include "QDebug"
#include <QCoreApplication>
struct style_t{
    const char* description;
    const char* style;
};

static const style_t styles[]={

    //Labels
    {"# Fuente","*{font-family:\"Tungsten Semibold\";font-size: 20px;font-weight: 200;}"},
    {"# MesAño","QLabel#lbMesAnio               {font-size: 30px;color: #108F34;}"},
    {"# DiasSemana","QLabel#lbDiaSemana         {font-size: 24px;color: #108F34;}"},
    {"# Dia","QLabel#lbDia                      {font-size: 18px;color: #0D3894;}"},
    {"# NombreFarmacia","QLabel#lbFarmacia      {font-size: 24px;color: #108F34;}"},
    {"# DireccionFarmacia","QLabel#lbDireccion  {font-size: 20px;color: #0D3894;}"},
    {"# TelefonoFarmacia","QLabel#lbTelefono    {font-size: 20px;color: #0D3894;}"},
    {"# Select Labels","QLabel#lbSelect         {font-size: 20px;color: #108F34;}"},


    // Frames

    {"# frames","QFrame#generalFr {border:2px groove #0D3894;}"},
    {"# frames","QWidget#generalWid {background-color: #E8FCEE;}"},
    {"# frames","QFrame#selectFr {border:2px groove #0D3894;background-color: #E8EEFB;}"},
    {"# Magic Frame", "MagicFrame[current=\"false\"] {border:2px groove #0D3894;background-color : none;}"},
    {"# Magic Frame","MagicFrame[current=\"true\"] {border:2px groove #0D3894;background-color: #D0DEFB;}"},
    {"# Magic Frame", "MagicFrame[onFocus=\"false\"] {border:2px groove #0D3894;background-color : none;}"},
    {"# Magic Frame","MagicFrame[onFocus=\"true\"] {border:2px groove #0D3894;background-color: #D0DEFB;}"},


    // Botones
    {"# MenuBar","QMenuBar {font-size: 20px;color: #108F34;border:2px groove #0D3894;background-color: #ECF2F9;border-bottom:none;}"},
    {"# Menu","QMenu {font-size: 20px;color: #108F34;border:1px groove #0D3894 ;border-top:none;border-bottom: 2px groove #0D3894;background-color: #ECF2F9;}"},


    {"# Save Button","MagicFrame#saveButton[enabled=\"false\"]{border:2px groove #ECF2F9;background-color: #ECF2F9;}"},
    {"# Save Label","QLabel#saveLb {font-size: 30px;color: #108F34;}"},
    {"# Save Label","QLabel#saveLb[enabled=\"false\"] {font-size: 30px;color: none;}"},











    {nullptr,nullptr}
};

static const char* appName = "FarmaLendario";
static const char* appVersion = "0.1.0";


Config::Config()
{
    QCoreApplication *app = QCoreApplication::instance();
    app->setApplicationName(appName);
    app->setApplicationVersion(appVersion);
}

QString Config::getStyles()
{
    static bool first = true;
    QString s;
    const style_t *t = &styles[0];
    while(t->description != nullptr){
        if(first){
            qDebug() << QString(t->style);
        }
        s.append(t->style);
        t++;
    }
    first = false;
    return s;
}

QString Config::getAppName()
{
    return appName;
}

QString Config::getVersion()
{
    return appVersion;
}
