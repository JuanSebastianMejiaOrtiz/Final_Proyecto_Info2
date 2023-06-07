
#ifndef OBJECT_H
#define OBJECT_H

#include "global_macros.h"
#include "control_sprite.h"

class Object : public control_sprite
{
    Q_OBJECT
public:
    Object();

    void Move_Object(int x, int y);

    //Set and Get Methods
    void SetID(short nid);
    short GetID();

private:
    short id;

};

#endif // OBJECT_H
