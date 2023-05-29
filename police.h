
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
    Object *Cosas[enemy_Cantidad_Cosas];
    QTimer *timer;

};

#endif // POLICE_H
