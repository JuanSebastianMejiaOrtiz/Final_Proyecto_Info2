
#include "police.h"

Police::Police()
{
    //Assign Memory for Attributes
    timer = new QTimer;
    end_timer = new QTimer;
    Throw_timer = new QTimer;
    Cosa = new Object;
    cosa_timer = new QTimer;

    //Set Default Values
    launch = false;
    Enemy_Animation_Actual_Frame = 0;
    Enemy_Throw_Frecuency = enemy_Throw_Frecuency;
    Enemy_Throw_Animation_Speed = enemy_Throw_Animation_Speed;
    Enemy_Walk_Animation_Speed = enemy_Walk_Animation_Speed;
        //Fisicas
    ax = object_aceleration_x;
    ay = object_aceleration_y;
    vx = object_speed_x;
    vy = object_speed_y;
    T = object_Periodo_de_Muestreo / 1000;
    f = 10;

    //Load Image
    QPixmap img(":/Resources/Enemy/Sprite_Police_Full.png");
    *full = img.copy();
    Set_Width_Sprite(enemy_ancho);
    Set_Height_Sprite(enemy_alto);

    //Connect for All Signals
        //timer for animations
            //Idle Animation
    connect(timer, SIGNAL(timeout()), this, SLOT(Animation_Idle()));
            //Throw Animation
    connect(Throw_timer, SIGNAL(timeout()), this, SLOT(Throwing()));
            //Stop Animation
    connect(end_timer, SIGNAL(timeout()), this, SLOT(Game_Over_Stop()));
            //Object Move
    connect(cosa_timer, SIGNAL(timeout()), this, SLOT(Launched()));

    //Set Pos
    setPos(enemy_pos_x_initial, enemy_pos_y_initial);
    Cosa->setPos(-object_ancho, 0);

    //Start timers
    timer->start(Enemy_Walk_Animation_Speed);
    Throw_timer->start(Enemy_Throw_Frecuency);
    cosa_timer->start(object_Periodo_de_Muestreo);
}

Police::~Police()
{
    delete timer;
    delete Cosa;
    delete end_timer;
    delete cosa_timer;
    delete Throw_timer;
}

void Police::Throw_Animation()
{
    if (Get_Enemy_Animation_Actual_Frame() < enemy_Throw_Animation_Frame_Ammount){
        int frame;
        frame = Enemy_Animation_Actual_Frame + enemy_Idle_Animation_Frame_Ammount;
        Select_sprite(frame, 0);
        Scale_sprite(Scale_Characters);
        Show_Sprite(true);

        Enemy_Animation_Actual_Frame++;

        Move_Object();
    }
    else{
        Enemy_Animation_Actual_Frame = 0;
        launch = false;
        timer->start(Enemy_Walk_Animation_Speed);
    }
}

void Police::Idle_Animation()
{
    if (Get_Enemy_Animation_Actual_Frame() < enemy_Idle_Animation_Frame_Ammount){
        Select_sprite(Enemy_Animation_Actual_Frame, 0);
        Scale_sprite(Scale_Characters);
        Show_Sprite(true);
        Enemy_Animation_Actual_Frame++;
    }
    else{
        Enemy_Animation_Actual_Frame = 0;
    }
}

void Police::Stop_Animation()
{
    if (Get_Enemy_Animation_Actual_Frame() < enemy_Stop_Animation_Frame_Ammount){
        int frame = Enemy_Animation_Actual_Frame;
        Select_sprite(frame, 1);
        Scale_sprite(Scale_Characters);
        Show_Sprite(true);
        Enemy_Animation_Actual_Frame++;
    }
    else{
        end_timer->stop();
        Enemy_Animation_Actual_Frame = 0;
    }
}

void Police::Move_Object()
{
    if (Enemy_Animation_Actual_Frame == 1){
        int X, Y;

        X = 60;
        Y = 210;

        throwed = false;

        SetX(X);
        SetY(Y);
        Cosa->Move_Object(X, Y);
    }
    else if (Enemy_Animation_Actual_Frame == 2){
        int X, Y;

        X = 85;
        Y = 202;

        SetX(X);
        SetY(Y);
        Cosa->Move_Object(X, Y);
    }
    else if (Enemy_Animation_Actual_Frame == 3){
        std::srand((unsigned) std::time(NULL));
        float VX, VY;

        VX = object_speed_x;
        VY = 0 + std::rand() % 20;
        VY *= -1;

        SetVX(VX);
        SetVY(VY);

        throwed = true;
    }
}

void Police::Calcular_Fisicas()
{
    SetVX(GetVX() + ax * T * f);
    SetVY(GetVY() + (ay * T * f));
    SetX(GetX() + (vx * T * f));
    SetY(GetY() + (vy * T * f));
}



//SLOTS
void Police::Animation_Idle()
{
    if (!is_Launched()){
        Idle_Animation();
    }
    else Throw_Animation();
}

void Police::Game_Over_Stop()
{
    Stop_Animation();
}

void Police::Throwing()
{
    launch = true;
    Enemy_Animation_Actual_Frame = 0;
    timer->start(Enemy_Throw_Animation_Speed);
}

void Police::Launched()
{
    if (throwed){
        Calcular_Fisicas();
        Cosa->setPos(x, y);
    }
}


//Set and Get Methods
int Police::Get_Enemy_Animation_Actual_Frame()
{
    return Enemy_Animation_Actual_Frame;
}

void Police::Reset_Enemy_Animation_Actual_Frame()
{
    Enemy_Animation_Actual_Frame = 0;
}

bool Police::is_Launched()
{
    return launch;
}

void Police::SetX(float X)
{
    x = X;
}

float Police::GetX()
{
    return x;
}

void Police::SetY(float Y)
{
    y = Y;
}

float Police::GetY()
{
    return y;
}

void Police::SetVX(float VX)
{
    vx = VX;
}

float Police::GetVX()
{
    return vx;
}

void Police::SetVY(float VY)
{
    vy = VY;
}

float Police::GetVY()
{
    return vy;
}

void Police::SetAX(float AX)
{
    ax = AX;
}

float Police::GetAX()
{
    return ax;
}

void Police::SetAY(float AY)
{
    ay = AY;
}

float Police::GetAY()
{
    return ay;
}




