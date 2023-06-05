
#ifndef GLOBAL_MACROS_H
#define GLOBAL_MACROS_H

#include "macros_vitales.h"

//General
#define Scale_General 5
#define Scale_Characters (Scale_General - 0.2)
#define Scale_Objects (Scale_General * 0.8)
#define Scale_Background_x 3
#define Scale_Background_y 3.1
#define Check 1

//Main Character (mc)
    //Posicion
#define pos_x_initial_mc 600
#define pos_y_initial_mc 250
    //Movement
#define Walk_Speed_mc 8
    //Animation
#define _Walk_Animation_Speed_mc 100
#define Dead_Animation_Speed_mc 150


//Enemy
    //Position
#define enemy_pos_x_initial 30
#define enemy_pos_y_initial 250
    //Animation
#define enemy_Walk_Animation_Speed 200
#define enemy_Stop_Animation_Speed 400
#define enemy_Throw_Animation_Speed 100
    //Other
#define enemy_Throw_Frecuency 4000
#define enemy_Cantidad_Cosas 2
    //Object
        //Periodo
#define object_Periodo_de_Muestreo 1
        //Speed
#define object_start_vel_x 10 //(30 * Scale_Background_x)
#define object_start_vel_y 8 //(20 * Scale_Background_y)
        //Aceleration
#define object_aceleration_x 1
#define object_aceleration_y 1


//Background
#define background_timer_speed 20
#define background_movement_speed_px 20
#define background_reset_x ((background_width * Scale_Background_x) - (267 * Scale_Background_x))

#endif // GLOBAL_MACROS_H
