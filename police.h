
#ifndef POLICE_H
#define POLICE_H

#include "control_sprite.h"
#include "object.h"
#include "global_macros.h"

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

    Object *Cosa;

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

private:
    int Enemy_Animation_Actual_Frame;

    int Enemy_Walk_Animation_Speed;
    int Enemy_Throw_Frecuency;
    int Enemy_Throw_Animation_Speed;

    void Move_Object(int frame_actual);

private slots:
    void Animation_Idle();
    void Game_Over_Stop();
    void Throwing();

signals:
    void Para_Donde(Object *Objeto);

};

#endif // POLICE_H
