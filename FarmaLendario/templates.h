#ifndef TEMPLATES_H
#define TEMPLATES_H
#include <QFrame>
#include <QString>
#include "qevent.h"


enum FARMACIAS{
    FARM_PUSSETTO,
    FARM_MOLINA,
    FARM_VANDENBERGHE,
    FARM_CAULA,
    FARM_FENOGLIO,
    FARM_CAGLIERO,
    FARM_GARIONE,
    FARM_AIRASCA,
    FARM_ROBLEDO,
    FARM_GHIONE,
    FARM_ROSSO,
    FARM_ASTESANA,

    FARM_LAST

};

static const QString farmNombre[FARM_LAST]{
    "Pussetto",
    "Molina",
    "Vandenberghe",
    "Caula",
    "Fenoglio",
    "Cagliero",
    "Garione",
    "Airasca",
    "Robledo",
    "Ghione",
    "Rosso",
    "Astesana"

};

static const QString farmDireccion[FARM_LAST]{
    "Belgrano 402",
    "Zeballos 303",
    "Illia 596",
    "Ameghino 314",
    "Zeballos esq Crespo",
    "Zeballos 570",
    "9 de Julio 21",
    "Yrigoyen 1180",
    "Alem 407",
    "San Martín 45",
    "Italia 574",
    "Mitri 346"

};

static const QString farmTelefono[FARM_LAST]{
    "421004",
    "452357",
    "426786",
    "452357",
    "426602",
    "451772",
    "421844",
    "423556",
    "427071",
    "453400",
    "426435",
    "420723"
};

enum MONTH{
    MO_JANUARY,
    MO_FEBRUARY,
    MO_MARCH,
    MO_APRIL,
    MO_MAY,
    MO_JUNE,
    MO_JULY,
    MO_AUGUST,
    MO_SEPTEMBER,
    MO_OCTOBER,
    MO_NOVEMBER,
    MO_DECEMBER,

    MO_LAST
};
static const QString mesTxt[MO_LAST]{
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

enum DAY{
    DA_DOMINGO,
    DA_LUNES,
    DA_MARTES,
    DA_MIERCOLES,
    DA_JUEVES,
    DA_VIERNES,
    DA_SABADO,

    DA_LAST
};

static const QString dayTxt[DA_LAST]{
                                          "Domingo",
                                          "Lunes",
                                          "Martes",
                                          "Miercoles",
                                          "Jueves",
                                          "Viernes",
                                          "Sábado"
};

class MagicFrame : public QFrame
{
    Q_OBJECT
public:
    explicit MagicFrame(QWidget *parent = nullptr);


    bool isCurrent();
    void setCurrent(bool isCurrent);

public slots:
    void mousePressEvent(QMouseEvent *event);
    void enterEvent(QEnterEvent *event);
    void leaveEvent(QEvent *event);
private:
    bool current = false;

signals:
    void clicked();
    void currentSig(bool clicked);

};

#endif // TEMPLATES_H
