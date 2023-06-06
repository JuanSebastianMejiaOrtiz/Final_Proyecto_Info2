
#ifndef START_MENU_H
#define START_MENU_H

#include "control_sprite.h"
#include <QKeyEvent>

class Start_menu : protected control_sprite
{
public:
    Start_menu();

    void keyPressEvent(QKeyEvent *event);

signals:
    void Start_now(bool start);
};

#endif // START_MENU_H
