
#include "object.h"

Object::Object()
{
    //Assign memory to Attributes
    timer = new QTimer;

    //Set Default Values
    x = 0;
    y = 0;

    vx = object_start_vel_x;
    vy = object_start_vel_y;

    ax = object_aceleration_x;
    ay = object_aceleration_y;

    T = object_Periodo_de_Muestreo;
    f = 1;

    //Connect timer
    connect(timer, SIGNAL(timeout()), this, SLOT(Launched()));

    //Set Pixmap
    QPixmap img;
    img.load("://Resources/Objetos/roca.png");
    *full = img.copy();
    setPos(0, 0);
    Select_sprite(0, 0);
    Scale_sprite(Scale_Objects);
    Show_Sprite(true);
}

void Object::throwed(bool launched)
{
    if (launched){
        timer->start(T);
    }
    else{
        timer->stop();
    }
}

void Object::Move_Object(int x, int y)
{
    setPos(x, y);
}

void Object::Launch()
{
    setPos(x, y);
}

void Object::Calcular_Fisicas()
{
    vx += ax * T * f;
    vy += ay * T * f;
    x += vx * T * f;
    y += vy * T * f;
}

void Object::Launched()
{
    Calcular_Fisicas();
    Launch();
}


//Set and Get Methods
QPointF Object::Get_GoTo()
{
    return *Go_to;
}

void Object::Set_GoTo(QPointF Donde)
{
    *Go_to = Donde;
}

void Object::SetID(short nid)
{
    id = nid;
}

short Object::GetID()
{
    return id;
}

void Object::SetX(float X)
{
    x = X;
}

float Object::GetX()
{
    return x;
}

void Object::SetY(float Y)
{
    y = Y;
}

float Object::GetY()
{
    return y;
}

void Object::SetVX(float VX)
{
    vx = VX;
}

float Object::GetVX()
{
    return vx;
}

void Object::SetVY(float VY)
{
    vy = VY;
}

float Object::GetVY()
{
    return vy;
}

void Object::SetAX(float AX)
{
    ax = AX;
}

float Object::GetAX()
{
    return ax;
}

void Object::SetAY(float AY)
{
    ay = AY;
}

float Object::GetAY()
{
    return ay;
}

