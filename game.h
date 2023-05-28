
#ifndef GAME_H
#define GAME_H

#include "global_macros.h"
//Esenciales
#include "brayan.h"
#include "police.h"
#include "points.h"
//Complementos
#include "music.h"
#include "background.h"
#include "cinematic.h"

class game
{
public:
    game();
    ~game();

    void Verify_Collisions();

protected:
    Brayan MC;
    Police policia;

private:
    points puntaje;

    //Complementos
    background fondo;
    music musica;
    Cinematic initial_cinematic;
};

#endif // GAME_H
