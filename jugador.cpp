
#include "jugador.h"
Jugador::Jugador(){
    x = 0;
    y = 0;
    ancho = 0;
    alto = 0;
    vivo = true;
}

Jugador::Jugador(int x, int y, int ancho, int alto, int numero){
    this->x=x;
    this->y=y;
    this->ancho=ancho;
    this->alto=alto;
    this->numero=numero;
    vivo= true;
}

bool Jugador::colisiona(float px, float py, float rad){
    if(!vivo) return false;
    bool toca = px + rad > x && px - rad < x + ancho && py + rad > y && py - rad < y + alto;
    bool dentro = px > x && px < x + ancho && py > y && py < y + alto;
    return toca || dentro;
}
void Jugador::dibujar(QPainter& painter){
    if(!vivo) return;
    painter.setBrush(numero == 1 ? Qt::blue : Qt::red);
    painter.setPen(Qt::NoPen);
    painter.drawRect(x, y, ancho, alto);
}
