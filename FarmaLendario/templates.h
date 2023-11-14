#ifndef TEMPLATES_H
#define TEMPLATES_H
#include <QString>

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


#endif // TEMPLATES_H
