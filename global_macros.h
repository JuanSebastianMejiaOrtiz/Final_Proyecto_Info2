
#ifndef GLOBAL_MACROS_H
#define GLOBAL_MACROS_H

#include "macros_vitales.h"

//General
#define Scale 10
#define Scale_Characters (Scale - 0.2)
#define Check 1

//Main Character (mc)
    //Posicion
#define pos_x_initial_mc 600
#define pos_y_initial_mc 100
    //Movement
#define Walk_Speed_mc 6
    //Animation
#define _Walk_Animation_Speed_mc 100
#define Dead_Animation_Speed_mc 150


//Enemy
    //Position
#define enemy_pos_x_initial 60
#define enemy_pos_y_initial 60
    //Animation
#define enemy_Walk_Animation_Speed 200
#define enemy_Throw_Animation_Speed 200
#define enemy_Stop_Animation_Speed 400
    //Other
#define enemy_Cantidad_Cosas 2

#endif // GLOBAL_MACROS_H
