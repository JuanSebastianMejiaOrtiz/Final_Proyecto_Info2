
#ifndef GLOBAL_MACROS_H
#define GLOBAL_MACROS_H

#include "macros_vitales.h"

//General
#define Scale_General 3
#define Scale_Characters (Scale_General - 1)
#define Scale_Objects (Scale_General)
#define Scale_Background_x 3
#define Scale_Background_y 3.09
#define Check 1

//Main Character (mc)
    //Posicion
#define pos_x_initial_mc 500
#define pos_y_initial_mc 250
    //Movement
#define Walk_Speed_mc 8
    //Animation
#define _Walk_Animation_Speed_mc 500
#define Dead_Animation_Speed_mc 400


//Enemy
    //Position
#define enemy_pos_x_initial 30
#define enemy_pos_y_initial 250
    //Animation
#define enemy_Walk_Animation_Speed 1000
#define enemy_Stop_Animation_Speed 300
#define enemy_Throw_Animation_Speed 150
    //Other
#define enemy_Throw_Frecuency 4000
#define enemy_Cantidad_Cosas 2
    //Object
        //Periodo
#define object_Periodo_de_Muestreo 100
        //Aceleration
#define object_aceleration_x 2
#define object_aceleration_y 2


//Points
#define points_normal_frecuency 1000
#define points_extra_frecuency 10000


//Background
#define background_timer_speed 20
#define background_movement_speed_px 12

#endif // GLOBAL_MACROS_H
