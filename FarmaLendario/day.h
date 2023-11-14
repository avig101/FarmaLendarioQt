#ifndef DAY_H
#define DAY_H

#include <QFrame>
#include <QLabel>
#include "templates.h"

class Day : public QFrame
{
    Q_OBJECT
public:
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
    enum Info{
        IN_NUMBER,
        IN_NAME,
        IN_DIR,
        IN_TEL,

        IN_LAST
    };

    explicit Day(QWidget *parent = nullptr, int number = 1,DAY dia = DA_LAST);
    FARMACIAS getDeTurno() const;
    void setDeTurno(FARMACIAS newDeTurno);

private:
    DAY day;
    int number;
    FARMACIAS deTurno;
    QLabel *info[IN_LAST];


signals:

};
static const QString dayTxt[Day::DA_LAST]{
                                          "Domingo",
                                          "Lunes",
                                          "Martes",
                                          "Miercoles",
                                          "Jueves",
                                          "Viernes",
                                          "Sábado"
};
static const QString infoObjectName[Day::IN_LAST]{
    "N°",
    "farmName",
    "farmDir",
    "farmPhone"
};

#endif // DAY_H
