#ifndef DAY_H
#define DAY_H

#include <QLabel>
#include "templates.h"


class Day : public MagicFrame
{
    Q_OBJECT

public:
    enum Info{
        IN_NUMBER,
        IN_NAME,
        IN_DIR,
        IN_TEL,

        IN_LAST
    };

    explicit Day(QWidget *parent = nullptr, int number = 1,DAY dia = DA_LAST);
    explicit Day();

    FARMACIAS getDeTurno() const;
    void setDeTurno(FARMACIAS newDeTurno);

    int getNumber() const;
    void setNumber(int newNumber);


private:
    DAY day;
    int number = -1;
    FARMACIAS deTurno;
    QLabel *info[IN_LAST];

};

static const QString infoObjectName[Day::IN_LAST]{
    "Dia",
    "Farmacia",
    "Direccion",
    "Telefono"
};

#endif // DAY_H
