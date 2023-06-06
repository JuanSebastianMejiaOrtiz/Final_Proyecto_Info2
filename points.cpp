
#include "points.h"

points::points()
{
    //Assign Memory to Attributes
    timer_points = new QTimer;
    extra_points = new QTimer;
    puntos = new unsigned int;

    //Set Default Values
    Reset_Points();

    //Connect all Signals
    connect(timer_points, SIGNAL(timeout()), this, SLOT(Sumar_Puntaje()));
    connect(extra_points, SIGNAL(timeout()), this, SLOT(Sumar_Extra()));

    timer_points->start(points_normal_frecuency);
    extra_points->start(points_extra_frecuency);
}

points::~points()
{
    delete timer_points;
    delete extra_points;
    delete puntos;
}

unsigned int points::Get_Points()
{
    return *puntos;
}

void points::Add_Points(unsigned int points)
{
    *puntos += points;
}

void points::Reset_Points()
{
    *puntos = 0;
}

void points::Sumar_Puntaje()
{
    unsigned int p = 1;
    Add_Points(p);
    emit Update_Points(Get_Points());
}

void points::Sumar_Extra()
{
    unsigned int p = 10;
    Add_Points(p);
    emit Update_Points(Get_Points());
}

