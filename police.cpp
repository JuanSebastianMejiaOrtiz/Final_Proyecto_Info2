
#include "police.h"

Police::Police()
{
    //Assign Memory for Attributes
    timer = new QTimer;
    end_timer = new QTimer;
    Throw_timer = new QTimer;
    Cosa = new Object;

    //Set Default Values
    launch = false;
    Enemy_Animation_Actual_Frame = 0;
    Enemy_Throw_Frecuency = enemy_Throw_Frecuency;
    Enemy_Throw_Animation_Speed = enemy_Throw_Animation_Speed;
    Enemy_Walk_Animation_Speed = enemy_Walk_Animation_Speed;

    //Load Image
    QPixmap img(":/Resources/Enemy/Sprite_Police_Full.png");
    *full = img.copy();
    Set_Width_Sprite(enemy_ancho);
    Set_Height_Sprite(enemy_alto);

    //Connect for all signals
        //timer for animations
    connect(timer, SIGNAL(timeout()), this, SLOT(Animation_Idle()));
    connect(Throw_timer, SIGNAL(timeout()), this, SLOT(Throwing()));
    connect(end_timer, SIGNAL(timeout()), this, SLOT(Game_Over_Stop()));

    //Set Pos
    setPos(enemy_pos_x_initial, enemy_pos_y_initial);
    Cosa->setPos(-object_ancho, 0);

    //Start timers
    timer->start(Enemy_Walk_Animation_Speed);
    Throw_timer->start(Enemy_Throw_Frecuency);
}

Police::~Police()
{
    delete timer;
    delete Cosa;
}

void Police::Throw_Animation()
{
    if (Get_Enemy_Animation_Actual_Frame() < enemy_Throw_Animation_Frame_Ammount){
        int frame = Enemy_Animation_Actual_Frame + enemy_Idle_Animation_Frame_Ammount;
        Select_sprite(frame, 0);
        Scale_sprite(Scale_Characters);
        Show_Sprite(true);

        Move_Object(Get_Enemy_Animation_Actual_Frame());

        Enemy_Animation_Actual_Frame++;
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
        Select_sprite(Enemy_Animation_Actual_Frame, 1);
        Scale_sprite(Scale_Characters);
        Show_Sprite(true);
        Enemy_Animation_Actual_Frame++;
    }
    else{
        end_timer->stop();
        Enemy_Animation_Actual_Frame = 0;
    }
}

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
    launch = !launch;
    Enemy_Animation_Actual_Frame = 0;
    timer->start(Enemy_Throw_Animation_Speed);
}

//Set and Get Methods
int Police::Get_Enemy_Animation_Actual_Frame()
{
    return Enemy_Animation_Actual_Frame;
}

bool Police::is_Launched()
{
    return launch;
}

void Police::Move_Object(int frame_actual)
{
    float x, y;
    if (frame_actual == 0){
        x = 10;
        y = 40;
        Cosa->Move_Object(x, y);
    }
    else if (frame_actual == 1){
        x = 50;
        y = 20;

        Cosa->SetVX(object_start_vel_x);
        Cosa->SetVY(object_start_vel_y);
        Cosa->SetX(x);
        Cosa->SetY(y);

        Cosa->Move_Object(Cosa->GetX(), Cosa->GetY());
    }
    else if (frame_actual == 2){
        Cosa->throwed(true);
        emit Para_Donde(Cosa);
    }
}
