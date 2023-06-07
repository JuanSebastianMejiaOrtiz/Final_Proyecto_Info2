
#include "object.h"

Object::Object()
{
    //Set Pixmap
    QPixmap img;
    img.load(":/Resources/Objetos/roca.png");
    *full = img.copy();
    Select_sprite(0, 0);
    Scale_sprite(Scale_Objects);
    Show_Sprite(true);
}

void Object::Move_Object(int x, int y)
{
    setPos(x, y);
}

//Set and Get Methods
void Object::SetID(short nid)
{
    id = nid;
}

short Object::GetID()
{
    return id;
}

