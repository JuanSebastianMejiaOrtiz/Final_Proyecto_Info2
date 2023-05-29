
#include "character.h"

Character::Character(int Start_Point_x, int Start_Point_y)
{
    //Assign Memory for Attributes
    Pos_x = new int;
    Pos_y = new int;
    direction = new char;
    timer = new QTimer;
    isAlive = new bool;

    //Set Default Values
    *Pos_x = Start_Point_x;
    *Pos_y = Start_Point_y;
    Movement_Speed = Walk_Speed_mc; //Revisar
    *isAlive = 1;

    //Set Initial Pos
    setPos(QPointF(*Pos_x, *Pos_y));
}

Character::~Character()
{
    delete Pos_x;
    delete Pos_y;
    delete direction;
    delete timer;
    delete isAlive;
}


//Set and Get Methods
void Character::Set_Direction(char car)
{
    *direction = car;
}

char Character::Get_Direction()
{
    return *direction;
}

void Character::Set_Pos_x(int new_pos)
{
    *Pos_x = new_pos;
}

int Character::Get_Pos_x()
{
    return *Pos_x;
}

void Character::Set_Pos_y(int new_pos)
{
    *Pos_y = new_pos;
}

int Character::Get_Pos_y()
{
    return *Pos_y;
}

void Character::Set_isAlive(bool LoD)
{
    *isAlive = LoD;
}

bool Character::Get_isAlive()
{
    return *isAlive;
}

void Character::Set_ID(short nID)
{
    id = nID;
}

short Character::Get_ID()
{
    return id;
}
