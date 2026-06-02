#include "proyectiles.h"
#include "ui_proyectiles.h"

proyectiles::proyectiles(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::proyectiles)
{
    ui->setupUi(this);
    connect(ui->botonsalir,&QPushButton::clicked,this,&proyectiles::botonvolver);

}

proyectiles::~proyectiles()
{
    delete ui;
}

void proyectiles::botonvolver(){
    emit volver();
}

void proyectiles::agregarcaja(int x, int y, int ancho, int alto){
    cajas.push_back(cajas_c(x,y,ancho,alto));
}

void proyectiles::agregarPelota(int x, int y, int velx, int vely, int rad){
    pelotas.push_back(Pelota(x,y,velx,vely,rad));
}

