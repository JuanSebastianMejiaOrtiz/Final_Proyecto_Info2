
#include "brayan.h"

Brayan::Brayan() : Character(pos_x_initial_mc, pos_y_initial_mc)
{
    //Assign Memory for Attributes

    //Set Default Values
    Dead_Actual_Frame = 0;
    Set_Direction('n');

    //Obtain QPixmap full
    QPixmap imagen;
    imagen.load("://Resources/Main_Char/MC_De_Prueba.png");
    *full = imagen.copy(0, 0, ancho_mainchar*number_cols_mc, alto_mainchar*number_lines_mc);

    //Animation
    Walk_Animation_Speed = _Walk_Animation_Speed_mc;
    Walk_Animation_Actual_Frame = 0;

    //Connect for all signals
    //Connect and Start Timer
    connect(timer, SIGNAL(timeout()), this, SLOT(Walk_Animation()));
        //Connect and Start Dead_Timer
    connect(&Dead_Timer, SIGNAL(timeout()), this, SLOT(Dead_Animation()));

    //Start timers
    //Walk Animation
    timer->start(Walk_Animation_Speed);
        //Dead Animation
    Dead_Timer.start(Dead_Animation_Speed_mc);
}

Brayan::~Brayan()
{

}

void Brayan::keyPressEvent(QKeyEvent *event)
{
    if (Get_isAlive()){
        //Movement
        if (event->key() == Qt::Key_W){
            Set_Direction('u');
            Move();
        }
        else if (event->key() == Qt::Key_S){
            Set_Direction('d');
            Move();
        }
        else Set_Direction('n');
    }
}


//Movement
void Brayan::Move()
{
    Movement();

    Walk_Animation();
}

//Change Position
void Brayan::Movement()
{
    if (Get_Direction() == 'u'){
        *Pos_y -= Movement_Speed;
    }
    else if (Get_Direction() == 'd'){
        *Pos_y += Movement_Speed;
    }

    setPos(QPointF(*Pos_x, *Pos_y));
}


//Animations
void Brayan::Idle_Animation()
{
    if (Walk_Animation_Actual_Frame < Walk_Animation_Frame_Ammount_mc){
        Select_sprite(Walk_Animation_Actual_Frame, 0);
        Scale_sprite(Scale_Characters);
        Show_Sprite(true);
        Walk_Animation_Actual_Frame++;
    }
    else{
        Walk_Animation_Actual_Frame = 0;
    }
}

    //Movement
void Brayan::Walk_Up_Animation()
{
    if (Walk_Animation_Actual_Frame < Walk_Animation_Frame_Ammount_mc){
        int frame = Idle_Animation_Frame_Ammount_mc + Walk_Animation_Frame_Ammount_mc;
        Select_sprite( (frame + Walk_Animation_Actual_Frame), 0);
        Scale_sprite(Scale_Characters);
        Show_Sprite(true);
        Walk_Animation_Actual_Frame++;
    }
    else{
        Walk_Animation_Actual_Frame = 0;
    }
}

void Brayan::Walk_Down_Animation()
{
    if (Walk_Animation_Actual_Frame < Walk_Animation_Frame_Ammount_mc){
        Select_sprite( (Idle_Animation_Frame_Ammount_mc + Walk_Animation_Actual_Frame), 0);
        Scale_sprite(Scale_Characters);
        Show_Sprite(true);
        Walk_Animation_Actual_Frame++;
    }
    else{
        Walk_Animation_Actual_Frame = 0;
    }
}

    //Dead
void Brayan::Dead(){
    if (Dead_Actual_Frame < Dead_Animation_Frame_Ammount_mc){
        Select_sprite(Dead_Actual_Frame, 1);
        Scale_sprite(Scale);
        Show_Sprite(1);
        Dead_Actual_Frame++;
    }
    else if (Dead_Actual_Frame == Dead_Animation_Frame_Ammount_mc){
        Dead_Timer.stop();
        Dead_Actual_Frame = 0;
    }
}


//SLOTS
//Animations
    //Movement
void Brayan::Walk_Animation()
{
    if (Get_Direction() == 'u'){
        Walk_Up_Animation();
    }
    else if (Get_Direction() == 'd'){
        Walk_Down_Animation();
    }
    else if (Get_Direction() == 'n'){
        Idle_Animation();
    }
}

    //Dead
void Brayan::Dead_Animation()
{
    if (!Get_isAlive()){
        Dead();
    }
}
