
#ifndef CONTROL_SPRITE_H
#define CONTROL_SPRITE_H

#include <QGraphicsPixmapItem>
#include <QTimer>

class control_sprite : public QObject, public QGraphicsPixmapItem
{
public:
    control_sprite();
    ~control_sprite();

    void Select_sprite(int x, int y);
    void Scale_sprite(float scale);
    void Show_Sprite(bool appear);

    QPixmap *full, *actual;
protected:
    int *width_sprite;
    int *height_sprite;
};

#endif // CONTROL_SPRITE_H
