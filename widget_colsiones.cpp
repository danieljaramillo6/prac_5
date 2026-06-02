#include "widget_colsiones.h"
#include "pelota.h"
#include <QTimer>
#include <Qpainter>

widget_colsiones::widget_colsiones() {}
widget_colsiones::widget_colsiones(QWidget *parent)
    : QWidget(parent)
{
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &widget_colsiones::actualizar);
    timer->start(16);

    agregarcaja(20,200,150,90);
   // agregarcaja(250,100,100,30);
    //agregarcaja(400,200,100,150);
    agregarcaja(250,300,50,60);
    agregarPelota(80, 100,  10,  -5, 20);
    //agregarPelota(60, 350, -10,  12, 20);
    agregarPelota(50, 70, 7,  8, 20);
    //agregarPelota(40, 100, -15,  -9, 20);
}

void widget_colsiones::agregarPelota(int x, int y, int velx, int vely,int rad){
    pelotas.push_back(Pelota(x,y,velx,vely,rad,0));
}

void widget_colsiones::agregarcaja(int x, int y, int ancho, int alto){
    cajas.push_back(cajas_c(x,y,ancho,alto));
}

void widget_colsiones::paintEvent(QPaintEvent *event){
    Q_UNUSED(event);
    QPainter p(this);
    p.fillRect(rect(), Qt::white);
    for(cajas_c caja:cajas){
        caja.dibujar(p);
    }
    for (Pelota pelota: pelotas){
        pelota.dibujar(p);
    }

}

void widget_colsiones::actualizar(){
    for (Pelota &pelota: pelotas){
        pelota.mover(width(),height(),cajas);
    }
    detectarcolision();
    update();
}

void widget_colsiones::detectarcolision(){
    int n = pelotas.size();

    for (int i = 0; i < n; i++) {
        if (!pelotas[i].getviva()) continue;
        for (int j = i+1; j < n; j++) {
            if (!pelotas[j].getviva()) continue;
            if (pelotas[i].colisionarpelota(pelotas[j])) {
                double m1 = pelotas[i].getrad() * pelotas[i].getrad();
                double m2 = pelotas[j].getrad() * pelotas[j].getrad();
                float vx = (m1*pelotas[i].getvelx() + m2*pelotas[j].getvelx()) / (m1 + m2);
                float vy = (m1*pelotas[i].getvely() + m2*pelotas[j].getvely()) / (m1 + m2);
                float x  = (pelotas[i].getx() + pelotas[j].getx()) / 2;
                float y  = (pelotas[i].gety() + pelotas[j].gety()) / 2;
                float r  = sqrt(m1 + m2);
                pelotas[i].muerta();
                pelotas[j].muerta();
                pelotas.append(Pelota(x, y, vx, vy, r,0));
            }
        }
    }
    for (int i=0; i < pelotas.size(); i++){
        if (!pelotas[i].getviva()){
            pelotas.erase(pelotas.begin()+i);
            i--;
        }
    }
    return;
}
