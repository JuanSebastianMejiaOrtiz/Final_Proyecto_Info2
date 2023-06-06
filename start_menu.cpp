
#include "start_menu.h"

Start_menu::Start_menu()
{

}

void Start_menu::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Space){
        //emit Start_now(true);
    }
}

