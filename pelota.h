#ifndef PELOTA_H
#define PELOTA_H
#include <Qpainter>
#include <QVector>
#include "cajas_c.h"
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

    //parte 2
    void mover2(int ancho,int alto,QVector<cajas_c> cajas);
    int calculardaño();
};

#endif // PELOTA_H
