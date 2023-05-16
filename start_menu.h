
#ifndef START_MENU_H
#define START_MENU_H

#include "control_sprite.h"

class Start_menu : protected control_sprite
{
public:
    Start_menu();

    void keyPressEvent(QKeyEvent *event);
};

#endif // START_MENU_H
