
#ifndef CHARACTER_H
#define CHARACTER_H

#include "control_sprite.h"
#include "global_macros.h"

class Character : public control_sprite
{
    Q_OBJECT
public:
    Character(int Start_Point_x, int Start_Point_y);
    ~Character();

    //Movement
    void Move();

    void Set_Direction(char car);
    char Get_Direction();

    void Set_Pos_x(int new_pos);
    int Get_Pos_x();

    void Set_Pos_y(int new_pos);
    int Get_Pos_y();

    void Set_Walk_Animation_Speed(short speed);
    short Get_Walk_Animation_Speed();

    void Set_isAlive(bool VoF);
    bool Get_isAlive();

    void Set_ID(short nID);
    short Get_ID();

    //Timer Animations
    QTimer *timer;

protected:
    //Position Variables
    int *Pos_x; //Character position in x
    int *Pos_y; //Character position in y
    char *direction; //u:up, d:down, r:right, l:left, n:none
    int Movement_Speed; //Pixels per cycle

    //Other
    bool *isAlive; //0:Dead, 1:Alive
    short id;

    //Animation Variables
        //Walk Animation
    short Walk_Animation_Speed; //1000: 1 second
    short Walk_Animation_Actual_Frame;
        //Dead_Animation
    int Dead_Actual_Frame;

};

#endif // CHARACTER_H
