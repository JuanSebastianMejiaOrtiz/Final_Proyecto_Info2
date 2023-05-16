
#ifndef CINEMATIC_H
#define CINEMATIC_H

#include "control_sprite.h"

class Cinematic : protected control_sprite
{
public:
    Cinematic();

    void Start_Cinematic();
private:
    QTimer *Frame_Speed;
};

#endif // CINEMATIC_H
