
#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "control_sprite.h"
#include "global_macros.h"

class background : public control_sprite
{
    Q_OBJECT
public:
    background();
    ~background();

    void moving(bool movement);
    bool Is_Moving() const;

    void Start_moving();
    void Stop_moving();

private:
    int actual_x;
    int actual_y;

    bool is_moving;

    QTimer *time;

private slots:
    void Move_Background();

};

#endif // BACKGROUND_H
