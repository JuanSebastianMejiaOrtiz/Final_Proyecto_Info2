
#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "control_sprite.h"

class background : public control_sprite
{
public:
    background();

    void Start_moving();
    void Stop_moving();

private:
    int actual_frame;

};

#endif // BACKGROUND_H
