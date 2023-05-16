
#ifndef POLICE_H
#define POLICE_H

#include "control_sprite.h"
#include "object.h"

class Police : protected control_sprite
{
public:
    Police();
    ~Police();

    void Throw_Animation();
    void Idle_Animation();
    void Stop_Animation();
protected:
    Object *Cosa1;
    Object *Cosa2;
    Object *Cosa3;
};

#endif // POLICE_H
