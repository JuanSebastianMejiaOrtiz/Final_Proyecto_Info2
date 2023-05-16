
#ifndef GAME_H
#define GAME_H

#include "cinematic.h"
#include "game_over.h"
#include "start_menu.h"
#include "music.h"
#include "level.h"

class game
{
public:
    game();

    void Change_Scene();
    void Verify_Collisions();
};

#endif // GAME_H
