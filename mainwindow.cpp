
#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    juego = new game;

    //Set Default Values to Attributes
    //playing = true;
    //playing = false;

    START_PLAYING();
}

MainWindow::~MainWindow()
{
    delete ui;

    //delete menu_start;
    //delete menu_over;
    delete juego;
}

void MainWindow::START_PLAYING()
{
    delete juego;
    juego = new game;

    //Connect all signals
    connect(juego, SIGNAL(Stop()), this, SLOT(stop_game()));
    connect(juego, SIGNAL(UPDATE_POINTS(uint)), this, SLOT(Update_Puntaje_Label(uint)));

    //Set Juego
    juego->setSceneRect(0, 0, (ui->Game_View_1->width() - 2), (ui->Game_View_1->height() - 2));
    ui->Game_View_1->setScene(juego);
        //Set Puntaje Label para playing==true
    ui->Puntaje->setGeometry(puntos_pos_playing_x, puntos_pos_playing_y, puntos_ancho_Label, puntos_alto_Label);
    ui->Puntaje->setStyleSheet("font-weight: bold; font-size: 24px; color: yellow;");
}

void MainWindow::Update_Puntaje_Label(unsigned int puntaje)
{
    QString qtexto = "Puntaje: ";

    qtexto += QString::number(puntaje);

    ui->Puntaje->setText(qtexto);
}

void MainWindow::stop_game()
{
    ui->Game_Over_Text->setGeometry(240, 200, 300, 150);
}


void MainWindow::on_Reset_clicked()
{
    ui->Game_Over_Text->setGeometry(240, -150, 300, 150);
    START_PLAYING();
}

