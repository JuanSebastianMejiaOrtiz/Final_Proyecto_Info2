
#include "game.h"

game::game()
{
    //Assign Memory for Attributes
    MC = new Brayan;

    MC->Select_sprite(0, 0);
    MC->Scale_sprite(Scale_Characters);
    MC->Show_Sprite(true);
    addItem(MC);
}

game::~game()
{
    delete MC;
    delete policia;
    delete puntaje;
    delete fondo;
    delete musica;
    delete initial_cinematic;
}

void game::keyPressEvent(QKeyEvent *event)
{
    MC->keyPressEvent(event);
}
