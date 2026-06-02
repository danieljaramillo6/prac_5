#ifndef CAJAS_C_H
#define CAJAS_C_H
#include <QPainter>
class cajas_c
{
protected:
    int x;
    int y;
    int ancho;
    int alto;
public:
    cajas_c();
    cajas_c(int x,int y, int ancho,int alto);
    void dibujar(QPainter &painter);
    int getx()const;
    int gety()const;
    int getancho()const;
    int getalto()const;
};

#endif // CAJAS_C_H
