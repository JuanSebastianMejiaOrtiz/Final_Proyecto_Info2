
#ifndef POLICE_H
#define POLICE_H

#include "control_sprite.h"
#include "object.h"
#include "global_macros.h"

class Police : protected control_sprite
{
    Q_OBJECT
public:
    Police();
    ~Police();

    void Throw_Animation();
    void Idle_Animation();
    void Stop_Animation();

protected:
    bool launch;

    Object *Cosas[enemy_Cantidad_Cosas];

    //Timers
        //Throw
    QTimer *Throw_timer;
        //Animation
    QTimer *timer;
    QTimer *end_timer;

private:
    int Enemy_Animation_Actual_Frame;
    int Enemy_Animation_Speed;
    int Enemy_Throw_Animation_Speed;

private slots:
    void Animation_Idle();
    void Game_Over_Stop();
    void Throwing();

};

#endif // POLICE_H
