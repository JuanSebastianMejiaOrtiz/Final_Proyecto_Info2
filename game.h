
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
    Q_OBJECT
public:
    game();
    ~game();

    void Verify_Collisions();

    void keyPressEvent(QKeyEvent *event);

private:
    Brayan *MC; //Brayan, Main Character
    Police *policia; //Police, Enemy
    points *puntaje; //Points

    //Complementary Attributes
    background *fondo; //Background
    music *musica; //Music and SFX
    Cinematic *initial_cinematic; //Initial Cinematic
    QTimer *Check_Update;

    //Methods
        //Set Objects in Scene
    void Set_MC(Brayan *mc);
    void Set_Enemy(Police *enemy);
    void Set_Background(background *background);

    //Interactions Main Character
    void Collisions_MC(Brayan *MainCharacter, Object *COSA);
    void MC_With_Limits(Brayan *mc);
    void MC_With_Object(Brayan *mc, Object *cosa, points *puntos);
    //Interactions Enemy
    void Enemy_Action(Police *enemy, Brayan *mc);
    void Object_timer_stop(Object *cosa);
    //Interacions Points
    void Stop_Background(background *fondo);

private slots:
    void Set_Para_Donde(Object *Cosa);
    void Update_Puntaje(unsigned int puntos);

    void Checking();

signals:
    void UPDATE_POINTS(unsigned int point);
};

#endif // GAME_H
