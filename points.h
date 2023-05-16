
#ifndef POINTS_H
#define POINTS_H

#include <QTimer>
//Se piensa usar un recuadro de texto para esto
//Toca buscar como hacerlo correctamente

class points
{
public:
    points();

    void Add_Points();
protected:
    QTimer *timer_points;
    unsigned int *puntos;
};

#endif // POINTS_H
