
#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>

#include "global_macros.h"
//Esenciales
#include "brayan.h"
#include "police.h"
#include "points.h"
//Complementos
#include "music.h"
#include "background.h"
#include "cinematic.h"

class game : public QGraphicsScene
{
public:
    game();
    ~game();

    void Verify_Collisions();

    void keyPressEvent(QKeyEvent *event);

protected:
    Brayan *MC; //Brayan, Main Character
    Police *policia; //Police, Enemy
    points *puntaje; //Puntos

private:
    //Atributos Complementos
    background *fondo; //Background
    music *musica; //Musica y SFX
    Cinematic *initial_cinematic; //Cinematica inicial

    //Metodos
    void Set_MC(Brayan *mc);
    void Set_Enemy(Police *enemy);
};

#endif // GAME_H
