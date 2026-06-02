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

