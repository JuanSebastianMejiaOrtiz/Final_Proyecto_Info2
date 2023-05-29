
#include "game.h"

game::game()
{
    //Assign Memory for Attributes
    MC = new Brayan;
    policia = new Police;

    //Set on Scene
    Set_MC(MC);
    Set_Enemy(policia);

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

void game::Set_MC(Brayan *mc)
{
    mc->Select_sprite(0, 0);
    mc->Scale_sprite(Scale_Characters);
    mc->Show_Sprite(true);
    addItem(mc);
}

void game::Set_Enemy(Police *enemy)
{
    enemy->Select_sprite(0, 0);
    enemy->Scale_sprite(Scale_Characters);
    enemy->Show_Sprite(true);
    addItem(enemy);
}
