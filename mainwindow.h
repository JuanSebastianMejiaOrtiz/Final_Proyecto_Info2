
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "start_menu.h"
#include "game.h"
#include "game_over.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    //Start Menu
    Start_menu menu_start;
    //Game Over Menu
    Game_over menu_over;
    //Main Game Screen
    game juego;

};

#endif // MAINWINDOW_H
