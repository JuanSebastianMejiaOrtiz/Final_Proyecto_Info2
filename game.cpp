
#include "game.h"

game::game()
{
    //Assign Memory for Attributes
    MC = new Brayan;
    policia = new Police;
    fondo = new background;
    puntaje = new points;
    Check_Update = new QTimer;
    musica = new music;

    //Set on Scene
    Set_Background(fondo);
    Set_MC(MC);
    Set_Enemy(policia);

    //Connect Signals
    connect(puntaje, SIGNAL(Update_Points(uint)), this, SLOT(Update_Puntaje(uint)));
    connect(Check_Update, SIGNAL(timeout()), this, SLOT(Checking()));
    connect(MC, SIGNAL(Stop_Playing()), this, SLOT(STOP()));

    Check_Update->start(Check);
}

game::~game()
{
    delete MC;
    delete policia;
    delete puntaje;
    delete fondo;
    delete musica;
    delete Check_Update;
    //delete initial_cinematic;
}

void game::keyPressEvent(QKeyEvent *event)
{
    MC->keyPressEvent(event);
}

bool game::is_GameOver()
{
    bool mcVivo, mcDeadFull;

    mcVivo = MC->Get_isAlive();
    mcDeadFull = MC->timer->isActive();

    if (!mcVivo){
        if (!mcDeadFull){
            return 1;
        }
    }
    return 0;
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
    addItem(enemy->Cosa);
}

void game::Set_Background(background *background)
{
    addItem(background);
}

void game::Collisions_MC(Brayan *MainCharacter, Object *COSA)
{
    MC_With_Limits(MainCharacter);
    MC_With_Object(MainCharacter, COSA, puntaje);
}

void game::MC_With_Limits(Brayan *mc)
{
    int y;
    char direction;
    int maxY = Window_Height - (alto_mainchar * Scale_Characters);

    y = mc->Get_Pos_y();

    if (y < 0){
        direction = 'd';
        mc->Set_Direction(direction);
        mc->Move();
    }
    else if (y > maxY){
        direction = 'u';
        mc->Set_Direction(direction);
        mc->Move();
    }
}

void game::MC_With_Object(Brayan *mc, Object *cosa, points *puntos)
{
    if (mc->collidesWithItem(cosa)){
        mc->timer->start(Dead_Animation_Speed_mc);
        mc->Set_isAlive(false);

        puntos->Stop_Timers();
        Stop_Background(fondo);
    }
}

void game::Enemy_Action(Police *enemy, Brayan *mc)
{
    bool a = mc->Get_isAlive();
    if (!a){
        enemy->timer->stop();
        enemy->Throw_timer->stop();
        enemy->Reset_Enemy_Animation_Actual_Frame();
        enemy->end_timer->start(enemy_Stop_Animation_Speed);
    }
}

void game::Object_Stop_Moving(Police *enemy)
{
    int X, Y;
    X = enemy->GetX();
    Y = enemy->GetY();
    if (X > Window_Width || Y > Window_Height){
        enemy->throwed = false;
    }
}

void game::Stop_Background(background *fondo)
{
    fondo->moving(false);
}

void game::Update_Puntaje(unsigned int puntos)
{
    emit UPDATE_POINTS(puntos);
}

void game::STOP()
{
    emit Stop();
}

void game::Checking()
{
    Collisions_MC(MC, policia->Cosa);
    Enemy_Action(policia, MC);
    Object_Stop_Moving(policia);
}
