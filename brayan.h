
#ifndef BRAYAN_H
#define BRAYAN_H

#include <QKeyEvent>

#include "character.h"

class Brayan : public Character
{
    Q_OBJECT
public:
    Brayan();
    ~Brayan();

    //Inputs
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

    void Move();

private:
    //Movement Methods
    void Movement();

    //Animation Methods
    //Movement
    void Idle_Animation();
    void Walk_Up_Animation();
    void Walk_Down_Animation();
        //Dead
    void Dead();

private slots:
    //Animations
    //Movement Animation
    void Walk_Animation();
        //Dead Animation
    void Dead_Animation();

};

#endif // BRAYAN_H
