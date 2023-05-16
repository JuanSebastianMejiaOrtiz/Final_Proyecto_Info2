
#ifndef LEVEL_H
#define LEVEL_H

#include "brayan.h"
#include "police.h"
#include "points.h"
#include "background.h"

class level
{
public:
    level();
    ~level();
protected:
    Brayan *mc;
    Police enemy;
    points *point;
    background *background_img;
    bool *playing;
};

#endif // LEVEL_H
