
#ifndef BRAYAN_H
#define BRAYAN_H

#include "character.h"

class Brayan : public Character
{
public:
    Brayan();

    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

    void Dead_Animation();
};

#endif // BRAYAN_H
