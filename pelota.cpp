#include "pelota.h"
#include <QPainter>
#include <QDebug>
#include <cmath>
Pelota::Pelota() {}
Pelota::Pelota(int x, int y, float velx, float vely, int rad,int masa){
    this->x=x;
    this->y=y;
    this->velx=velx;
    this->vely=vely;
    this->rad=rad;
    this->masa=masa;
    viva=true;
    qDebug() << "Pelota creada - velx:" << velx << "vely:" << vely;
}
Pelota::~Pelota(){

}

void Pelota::mover(int ancho, int alto, QVector<cajas_c> cajas){
    float px = x;
    float py = y;

    x+=velx;
    y+=vely;
    qDebug()<<"velx= "<<velx<<" vely: "<<vely;
    float e=0.9f;
//COLISION CAJAS
    bool der = colisionarcajader(cajas);
    bool iz  = colisionarcajaiz(cajas);
    bool up = colisionarcajaup(cajas);
    bool dw = colisionarcajadw(cajas);
    bool choque_lat = der || iz;
    bool choque_vert = up || dw;

    if(choque_lat && choque_vert){
        x=px;
        y=py;
    }if(choque_lat){
        velx = -velx * e;
    } else if(choque_vert){
        vely = -vely * e;
    }

//COLISION PAREDES:
    if (y - rad <= 0) {
        vely = -vely ;
        y = rad;
    }


    if (y + rad >= alto) {
        vely = -vely;
        y = alto - rad;
    }
    if (x - rad <= 0) {
        velx = -velx ;
        x = rad;
    }
    if (x + rad >= ancho) {
        velx = -velx ;
        x = ancho - rad;
    }
    if(velx<4 && velx>0)velx=4;
    else if(velx>-4 && velx<0)velx=-4;
    if(vely<4 && vely>0)vely=4;
    else if(vely>-4 && vely<0)vely=-4;

}

void Pelota::dibujar(QPainter &painter){
    painter.setBrush(Qt::white);
    painter.setPen(Qt::green);
    painter.drawEllipse(x-rad,y-rad,rad*2,rad*2);
}

bool Pelota::colisionarcajader(QVector<cajas_c> cajas){
    for(int i=0;i<cajas.size();i++){
        if(x-rad>=cajas[i].getx()+cajas[i].getancho()-3 &&  x-rad<= cajas[i].getx()+cajas[i].getancho()+3 &&(y+rad >= cajas[i].gety() && y-rad <= cajas[i].gety()+cajas[i].getalto())){
            if(dentrocaja(cajas[i]))x=cajas[i].getx()+cajas[i].getancho()+rad;
            return true;
        }
    }
    return false;
}

bool Pelota::colisionarcajaiz(QVector<cajas_c> cajas){
    for(int i=0;i<cajas.size();i++){
        if(x + rad >= cajas[i].getx()-3 && x + rad <= cajas[i].getx() +3 && (y+rad >= cajas[i].gety() && y-rad <= cajas[i].gety()+cajas[i].getalto())){
            if(dentrocaja(cajas[i])) x=cajas[i].getx()-rad;
            return true;
        }
    }
    return false;
}

bool Pelota::colisionarcajaup(QVector<cajas_c> cajas){
    for(int i=0;i<cajas.size();i++){
        if(y - rad >= cajas[i].gety() + cajas[i].getalto() -3 &&  y - rad <= cajas[i].gety() + cajas[i].getalto() + 3 &&(x+rad >= cajas[i].getx() && x-rad <= cajas[i].getx()+cajas[i].getancho())){
            if(dentrocaja(cajas[i]))y=cajas[i].gety()+cajas[i].getalto()+rad;
            return true;
        }
    }
    return false;
}

bool Pelota::colisionarcajadw(QVector<cajas_c> cajas){
    for(int i=0;i<cajas.size();i++){
        if(y + rad >= cajas[i].gety() -3 && y + rad <= cajas[i].gety() + 3 && (x+rad >= cajas[i].getx() && x-rad <= cajas[i].getx()+cajas[i].getancho())){
            if(dentrocaja(cajas[i]))y=cajas[i].gety()-rad;
            return true;
        }
    }
    return false;
}


bool Pelota::dentrocaja(cajas_c caja){
    if (x+rad>caja.getx() && x-rad<caja.getx()+caja.getancho() && y-rad<caja.gety()+caja.getalto() && y+rad>caja.gety()){
        return true;
    }
    else return false;
}

bool Pelota::colisionarpelota(Pelota &otra){
    double dx=otra.getx()-x;
    double dy=otra.gety()-y;
    double distancia=sqrt(dx*dx+dy*dy);
    return distancia<=rad+otra.getrad();
}
int Pelota::getx(){
    return x;
}

int Pelota::gety(){
    return y;
}

int Pelota::getrad(){
    return rad;
}

void Pelota::muerta(){
    viva=false;
    return;
}

float Pelota::getvelx(){
    return velx;
}

float Pelota::getvely(){
    return vely;
}

bool Pelota::getviva(){
    return viva;
}

//parte 2

int Pelota::calculardaño(){
    float vel=hypot(velx,vely);
    int daño=vel*masa;
    return daño;
}

void Pelota::mover2(int ancho, int alto, QVector<cajas_c> cajas){
    vely=vely-*2;

}
