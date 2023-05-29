
#include "police.h"

Police::Police()
{
    //Assign Memory for Attributes
    timer = new QTimer;
    for (short i = 0; i < enemy_Cantidad_Cosas; i++){
        Cosas[i] = new Object;
    }

    //Set Default Values
    Enemy_Animation_Actual_Frame = 0;
    Enemy_Animation_Speed = enemy_Walk_Animation_Speed;

    //Connect for all signals
        //timer for animations
    connect(timer, SIGNAL(timeout()), this, SLOT(Animations()));
    connect(end_timer, SIGNAL(timeout()), this, SLOT(Game_Over_Stop()));

    //Start timers
    timer->start(Enemy_Animation_Speed);
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

void Police::Animations()
{

}

void Police::Game_Over_Stop()
{
    Stop_Animation();
}

