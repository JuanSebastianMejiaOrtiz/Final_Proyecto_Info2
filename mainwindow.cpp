
#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    playing = 0;

    juego = new game;

    juego->setSceneRect(0, 0, (ui->Game_View_1->width() - 2), (ui->Game_View_1->height() - 2));

    ui->Game_View_1->setScene(juego);
}

MainWindow::~MainWindow()
{
    delete ui;

    delete menu_start;
    delete menu_over;
    delete juego;
}

