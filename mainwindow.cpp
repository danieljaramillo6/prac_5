#include "mainwindow.h"
#include "colisiones.h"
#include "proyectiles.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    connect(ui->b_colision, &QPushButton::clicked, this, &MainWindow::boton_col);
    connect(ui->b_proyectil, &QPushButton::clicked, this, &MainWindow::boton_proy);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::boton_col(){
    colisiones *c=new colisiones();
    c->show();
    this->hide();
    connect(c,&colisiones::volver,this,[this,c](){
        c->close();
        this->show();
    });
}

void MainWindow::boton_proy(){
    proyectiles *p= new proyectiles();
    p->show();
    this->hide();
    connect(p,&proyectiles::volver,this,[this,p](){
        p->close();
        this->show();
    });
}
