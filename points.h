
#ifndef POINTS_H
#define POINTS_H

#include <QTimer>
#include "global_macros.h"

class points : public QObject
{
    Q_OBJECT
public:
    points();
    ~points();

    unsigned int Get_Points();
    void Add_Points(unsigned int points);
    void Reset_Points();
private:
    QTimer *timer_points;
    QTimer *extra_points;

    unsigned int *puntos;

private slots:
    void Sumar_Puntaje();
    void Sumar_Extra();

signals:
    void Update_Points(unsigned int point);
};

#endif // POINTS_H
