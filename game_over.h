
#ifndef GAME_OVER_H
#define GAME_OVER_H

#include "control_sprite.h"

class Game_over : protected control_sprite
{
public:
    Game_over();

    void keyPressEvent(QKeyEvent *event);

};

#endif // GAME_OVER_H
