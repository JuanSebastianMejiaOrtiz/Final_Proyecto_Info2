
#include "police.h"

Police::Police()
{
    //Assign Memory for Attributes
    timer = new QTimer;
    end_timer = new QTimer;
    Throw_timer = new QTimer;
    for (short i = 0; i < enemy_Cantidad_Cosas; i++){
        Cosas[i] = new Object;
    }

    //Set Default Values
    launch = false;
    Enemy_Animation_Actual_Frame = 0;
    Enemy_Throw_Animation_Speed = enemy_Throw_Animation_Speed;
    Enemy_Animation_Speed = enemy_Walk_Animation_Speed;

    //Load Image
    QPixmap img;

    //Connect for all signals
        //timer for animations
    connect(timer, SIGNAL(timeout()), this, SLOT(Animation_Idle()));
    connect(Throw_timer, SIGNAL(timeout()), this, SLOT(Throwing()));
    connect(end_timer, SIGNAL(timeout()), this, SLOT(Game_Over_Stop()));

    //Start timers
    timer->start(Enemy_Animation_Speed);
    Throw_timer->start(Enemy_Throw_Animation_Speed);
}

Police::~Police()
{
    delete timer;
    for (short i = 0; i < enemy_Cantidad_Cosas; i++){
        delete Cosas[i];
    }
}

void Police::Throw_Animation()
{
    if (Enemy_Animation_Actual_Frame < enemy_Stop_Animation_Frame_Ammount){
        int frame = Enemy_Animation_Actual_Frame + enemy_Walk_Animation_Frame_Ammount;
        frame += enemy_Idle_Animation_Frame_Ammount;

        Select_sprite(frame, 0);
        Scale_sprite(Scale);
        Show_Sprite(true);
        Enemy_Animation_Actual_Frame++;
    }
    else{
        Enemy_Animation_Actual_Frame = 0;
        launch = false;
    }
}

void Police::Idle_Animation()
{
    if (Enemy_Animation_Actual_Frame < enemy_Stop_Animation_Frame_Ammount){
        Select_sprite(Enemy_Animation_Actual_Frame, 0);
        Scale_sprite(Scale);
        Show_Sprite(true);
        Enemy_Animation_Actual_Frame++;
    }
    else{
        Enemy_Animation_Actual_Frame = 0;
    }
}

void Police::Stop_Animation()
{
    if (Enemy_Animation_Actual_Frame < enemy_Stop_Animation_Frame_Ammount){
        Select_sprite(Enemy_Animation_Actual_Frame, 1);
        Scale_sprite(Scale);
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
    if (!launch){
        Idle_Animation();
    }
}

void Police::Game_Over_Stop()
{
    Stop_Animation();
}

void Police::Throwing()
{
    if (launch){
        Throw_Animation();
    }
}

