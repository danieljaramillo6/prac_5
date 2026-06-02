#ifndef CAJAS_P_H
#define CAJAS_P_H
#include "cajas_c.h"

class cajas_p : public cajas_c
{
private:
    int vida;
public:
    cajas_p();
    cajas_p(int x,int y,int alto,int ancho,int vida);
    void dañar(int daño);
};

#endif // CAJAS_P_H
