#include "colisiones.h"
#include "ui_colisiones.h"


colisiones::colisiones(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::colisiones)
{
    ui->setupUi(this);
    connect(ui->botonvolver, &QPushButton::clicked, this, &colisiones::botonVolver);
    widget_colsiones *simulacion = new widget_colsiones(this);
    simulacion->setGeometry(0, 0, 600, 500);
}

colisiones::~colisiones()
{
    delete ui;
}

void colisiones::botonVolver(){
    emit volver();
}
