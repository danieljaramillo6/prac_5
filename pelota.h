#ifndef PELOTA_H
#define PELOTA_H
#include <Qpainter>
#include <QVector>
#include "cajas_c.h"
#include "cajas_p.h"
class Pelota
{
private:
    int masa;
    int x;
    int y;
    float velx;
    float vely;
    int rad;
    bool viva;
    int reb;
public:
    Pelota();
    Pelota(int x,int y,float velx,float vely,int rad,int masa);
    ~Pelota();
    bool colisionlateralcaja(QVector<cajas_c> cajas);
    bool colisionarribacaja(QVector<cajas_c> cajas);
    bool colisionarpelota(Pelota &pelota);
    bool colisionarcajader(QVector<cajas_c> cajas);
    bool colisionarcajaup(QVector<cajas_c> cajas);
    bool colisionarcajadw(QVector<cajas_c> cajas);
    bool colisionarcajaiz(QVector<cajas_c> cajas);
    bool dentrocaja(cajas_c caja);
    void mover(int ancho,int alto,QVector<cajas_c> cajas);
    void dibujar(QPainter &painter);
    int getx();
    int gety();
    int getrad();
    float getvelx();
    float getvely();
    bool getviva();
    void muerta();
    void setpos(int x,int y);

    //parte 2
    void mover2(int ancho,int alto,QVector<cajas_p> cajas);
    int calculardaño();
    bool colisionarcajader2(QVector<cajas_p> cajas);
    bool colisionarcajaup2(QVector<cajas_p> cajas);
    bool colisionarcajadw2(QVector<cajas_p> cajas);
    bool colisionarcajaiz2(QVector<cajas_p> cajas);
    void setVelx(float v){ velx = v; }
    void setVely(float v){ vely = v; }
};

#endif // PELOTA_H
