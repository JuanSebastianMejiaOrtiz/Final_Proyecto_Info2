
#include "game.h"

game::game()
{
    //Assign Memory for Attributes
    MC = new Brayan;
    policia = new Police;
    fondo = new background;
    puntaje = new points;
    Check_Update = new QTimer;

    //Set on Scene
    Set_Background(fondo);
    Set_MC(MC);
    Set_Enemy(policia);

    //Connect Signals
    connect(policia, SIGNAL(Para_Donde(Object*)), this, SLOT(Set_Para_Donde(Object*)));
    connect(puntaje, SIGNAL(Update_Points(uint)), this, SLOT(Update_Puntaje(uint)));
    connect(Check_Update, SIGNAL(timeout()), this, SLOT(Checking()));

    Check_Update->start(Check);
}

game::~game()
{
    delete MC;
    delete policia;
    delete puntaje;
    delete fondo;
    delete musica;
    delete initial_cinematic;
    delete Check_Update;
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
    short idmc = mc->Get_ID();
    short idcosa = cosa->GetID();
    if (mc->collidesWithItem(cosa) && (idmc == idcosa)){
        mc->timer->start(Dead_Animation_Speed_mc);
        mc->Set_isAlive(false);

        puntos->Stop_Timers();
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

void game::Object_timer_stop(Object *cosa)
{
    int x = cosa->GetX();
    int y = cosa->GetY();
    if (x > Window_Width || y > Window_Height){
        cosa->SetVX(0);
        cosa->SetVY(0);
    }
}

void game::Stop_Background(background *fondo)
{
    fondo->moving(false);
}

void game::Set_Para_Donde(Object *Cosa)
{
    float vx, vy;
    Cosa->SetID(MC->Get_ID());

    //int idCosa;
    //idCosa = Cosa->GetID();

    vx = 4;
    vy = 8;
    vy *= -1;

    Cosa->SetVY(vy);
    Cosa->SetVX(vx);

//    if (idCosa == 0){
//        vx = 4;
//        vy = 8;
//        vy *= -1;

//        Cosa->SetVY(vy);
//        Cosa->SetVX(vx);
//    }
//    else if (idCosa == 1){
//        vx = 20;
//        vy = -30;

//        Cosa->SetVY(vy);
//        Cosa->SetVX(vx);
//    }
//    else if (idCosa == 2){
//        vx = 20;
//        vy = -30;

//        Cosa->SetVY(vy);
//        Cosa->SetVX(vx);
//    }
//    else if (idCosa == 3){
//        vx = 20;
//        vy = -30;

//        Cosa->SetVY(vy);
//        Cosa->SetVX(vx);
//    }
//    else if (idCosa == 4){
//        vx = 20;
//        vy = -30;

//        Cosa->SetVY(vy);
//        Cosa->SetVX(vx);
//    }
//    else if (idCosa == 5){
//        vx = 12;
//        vy = -20;

//        Cosa->SetVY(vy);
//        Cosa->SetVX(vx);
//    }
}

void game::Update_Puntaje(unsigned int puntos)
{
    emit UPDATE_POINTS(puntos);
}

void game::Checking()
{
    Collisions_MC(MC, policia->Cosa);
    Enemy_Action(policia, MC);
    Object_timer_stop(policia->Cosa);
}
