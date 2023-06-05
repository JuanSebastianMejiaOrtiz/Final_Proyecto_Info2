
#include "background.h"

background::background()
{
    //Assign Memory to Attributes
    time = new QTimer;

    //Set Default Values
    moving(true);
    actual_x = 0;
    actual_y = 0;

    //Set Full Pixmap
    QPixmap img("://Resources/Background/Background_Final_Project.png");
    *full = img.copy();

    //Set Actual Pixmap
    Set_Width_Sprite(background_width);
    Set_Height_Sprite(background_height);
    Select_sprite(0,0);
    Scale_sprite(Scale_Background_x, Scale_Background_y);
    Show_Sprite(true);
    setPos(0, 0);

    //Connect Signals
    connect(time, SIGNAL(timeout()), this, SLOT(Move_Background()));

    //Start Timers
    time->start(background_timer_speed);
}

background::~background()
{
    delete time;
}

void background::moving(bool movement)
{
    is_moving = movement;
}

bool background::Is_Moving() const
{
    return is_moving;
}

void background::Start_moving()
{
    int move = background_movement_speed_px;
    actual_x += move;

    if (actual_x <= (background_reset_x)){
        setPos((actual_x * -1), actual_y);
    }
    else{
        actual_x = 0;
        setPos(actual_x, actual_y);
    }
}

void background::Stop_moving()
{
    time->stop();
    actual_x = 0;
    actual_y = 0;
}

void background::Move_Background()
{
    if (Is_Moving()){
        Start_moving();
    }
    else{
        Stop_moving();
    }
}

