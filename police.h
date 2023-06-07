
#ifndef POLICE_H
#define POLICE_H

#include "control_sprite.h"
#include "object.h"
#include <cstdlib>
#include <ctime>
#include "global_macros.h"

#include <iostream>

class Police : public control_sprite
{
    Q_OBJECT
public:
    Police();
    ~Police();

    void Throw_Animation();
    void Idle_Animation();
    void Stop_Animation();

    int Get_Enemy_Animation_Actual_Frame();
    void Reset_Enemy_Animation_Actual_Frame();

    bool is_Launched();

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

    Object *Cosa;

    bool throwed;

    //Timers
        //Animation
            //Throw
    QTimer *Throw_timer;
            //Idle
    QTimer *timer;
            //Stop
    QTimer *end_timer;

protected:
    bool launch;

    float x, y;
    float vx, vy;
    float ax, ay;
    float T;
    float f;

    void Launch();
    void Calcular_Fisicas();

private:
    int Enemy_Animation_Actual_Frame;

    int Enemy_Walk_Animation_Speed;
    int Enemy_Throw_Frecuency;
    int Enemy_Throw_Animation_Speed;

    QTimer *cosa_timer;

    void Move_Object();

private slots:
    void Animation_Idle();
    void Game_Over_Stop();
    void Throwing();

    void Launched();

};

#endif // POLICE_H
