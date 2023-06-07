
#ifndef MACROS_VITALES_H
#define MACROS_VITALES_H

//  WARNING    Esto puede cambiar el funcionamiento base del juego

//General
#define Window_Width 800
#define Window_Height 600
#define ID_Change_px 100

//Main character
    //Medidas
#define alto_mainchar 155
#define ancho_mainchar 150
    //Animation
#define Walk_Animation_Frame_Ammount_mc 0
#define Idle_Animation_Frame_Ammount_mc 2
#define Dead_Animation_Frame_Ammount_mc 3
#define number_lines_mc 2
#define number_cols_mc 10


//Enemy
    //Medidas
#define enemy_ancho 129
#define enemy_alto 105
    //Animation
#define enemy_Idle_Animation_Frame_Ammount 2
#define enemy_Throw_Animation_Frame_Ammount 3
#define enemy_Stop_Animation_Frame_Ammount 3


//Objects
#define object_ancho 101
#define object_alto 70


//Background
#define background_width 3790
#define background_height 194
#define background_reset_x ((background_width * Scale_Background_x) - (267 * Scale_Background_x))


//Puntaje
    //Medidas
#define puntos_alto_Label 50
#define puntos_ancho_Label 230
    //Position
        //Playing
#define puntos_pos_playing_x 10
#define puntos_pos_playing_y 10
        //Other Screens
#define puntos_pos_GameOver_x 10
#define puntos_pos_GameOver_y 10

#endif // MACROS_VITALES_H
