#include "cajas_c.h"

cajas_c::cajas_c() {}
cajas_c::cajas_c(int x, int y, int ancho, int alto){
    this->x=x;
    this->y=y;
    this->ancho=ancho;
    this->alto=alto;
}

void cajas_c::dibujar(QPainter &painter){
    painter.setBrush(Qt::gray);
    painter.setPen(Qt::NoPen);
    painter.drawRect(x, y, ancho, alto);
}

int cajas_c::getx()const{
    return x;
}

int cajas_c::gety()const{
    return y;
}

int cajas_c::getalto()const{
    return alto;
}

int cajas_c::getancho()const{
    return ancho;
}
