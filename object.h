
#ifndef OBJECT_H
#define OBJECT_H

#include "global_macros.h"
#include "control_sprite.h"

class Object : public control_sprite
{
    Q_OBJECT
public:
    Object();

    void throwed(bool launched);

    void Move_Object(int x, int y);

    //Set and Get Methods
    QPointF Get_GoTo();
    void Set_GoTo(QPointF Donde);

    void SetID(short nid);
    short GetID();

    void SetX(float X);
    float GetX();

    void SetY(float Y);
    float GetY();

    void SetVX(float VX);
    float GetVX();

    void SetVY(float VY);
    float GetVY();

    void SetAX(float AX);
    float GetAX();

    void SetAY(float AY);
    float GetAY();


private:
    QTimer *timer;
    QPointF *Go_to;
    short id;

    float x, y;
    float vx, vy;
    float ax, ay;
    float T;
    float f;

    void Launch();
    void Calcular_Fisicas();

private slots:
    void Launched();
};

#endif // OBJECT_H
