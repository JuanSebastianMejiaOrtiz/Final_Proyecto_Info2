
#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Assign Memory to Attributes
    juego = new game;

    //Set Default Values to Attributes
    playing = 0;

    //Connect all signals
    connect(juego, SIGNAL(UPDATE_POINTS(uint)), this, SLOT(Update_Puntaje_Label(uint)));

    //Set Juego
    juego->setSceneRect(0, 0, (ui->Game_View_1->width() - 2), (ui->Game_View_1->height() - 2));
    ui->Game_View_1->setScene(juego);
        //Set Puntaje Label para playing==true
    ui->Puntaje->setStyleSheet("font-weight: bold; font-size: 24px; color: yellow;");
}

MainWindow::~MainWindow()
{
    delete ui;

    delete menu_start;
    delete menu_over;
    delete juego;
}

void MainWindow::Update_Puntaje_Label(unsigned int puntaje)
{
    QString qtexto = "Puntaje: ";

    qtexto += QString::number(puntaje);

    ui->Puntaje->setText(qtexto);
}

