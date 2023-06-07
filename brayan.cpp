
#include "brayan.h"

Brayan::Brayan() : Character(pos_x_initial_mc, pos_y_initial_mc)
{
    //Assign Memory for Attributes

    //Set Default Values
    Dead_Actual_Frame = 0;
    Set_Direction('n');
    Set_ID(0);

    //Obtain QPixmap full
    QPixmap imagen(":/Resources/Main_Char/Brayan_Final_Project_Full.png");
    *full = imagen.copy();
    Set_Width_Sprite(alto_mainchar);
    Set_Height_Sprite(ancho_mainchar);

    //Animation
    Walk_Animation_Speed = _Walk_Animation_Speed_mc;
    Walk_Animation_Actual_Frame = 0;

    //Connect for all signals
        //Connect and Start Timer
    connect(timer, SIGNAL(timeout()), this, SLOT(Animations()));

    //Start timers
        //Animations
    timer->start(Walk_Animation_Speed);
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
    if (Walk_Animation_Actual_Frame < Idle_Animation_Frame_Ammount_mc){
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
        frame += Walk_Animation_Actual_Frame;
        Select_sprite(frame, 0);
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
        int frame = Idle_Animation_Frame_Ammount_mc + Walk_Animation_Actual_Frame;
        Select_sprite(frame, 0);
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
        Scale_sprite(Scale_Characters);
        Show_Sprite(1);
        Dead_Actual_Frame++;
    }
    else if (Dead_Actual_Frame == Dead_Animation_Frame_Ammount_mc){
        timer->stop();
        Dead_Actual_Frame = 0;
        emit Stop_Playing();
    }
}


//SLOTS
//Animations
    //Movement
void Brayan::Walk_Animation()
{
    if (Get_Direction() == 'u'){
        //Walk_Up_Animation();
        Idle_Animation();
    }
    else if (Get_Direction() == 'd'){
        //Walk_Down_Animation();
        Idle_Animation();
    }
    else if (Get_Direction() == 'n'){
        Idle_Animation();
    }
}

    //Dead
void Brayan::Dead_Animation()
{
    Dead();
}

void Brayan::Animations(){
    if (Get_isAlive()){
        Walk_Animation();
    }
    else{
        Dead_Animation();
    }
}
