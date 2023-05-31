
#ifndef OBJECT_H
#define OBJECT_H

#include "control_sprite.h"

class Object : protected control_sprite
{
public:
    Object();

    void Launched_Animation();
protected:
    QTimer *time;
    QPointF *Go_to;
};

#endif // OBJECT_H
