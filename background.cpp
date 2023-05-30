
#include "background.h"

background::background()
{
    //Set Default Values
    actual_frame = 0;

    //Set Full Pixmap
    QPixmap img;
    img.load("");
    *full = img.copy();
}

void background::Start_moving()
{

}

void background::Stop_moving()
{

}

