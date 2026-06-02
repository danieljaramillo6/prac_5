#include "cajas_p.h"

cajas_p::cajas_p() {}

cajas_p::cajas_p(int x, int y, int alto, int ancho, int vida):cajas_c(x,y,ancho,alto){
    this->vida=vida;
}

void cajas_p::dañar(int daño){
    vida-=daño;
}

int cajas_p::getVida(){
    return vida;
}
