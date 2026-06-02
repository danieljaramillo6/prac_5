#ifndef JUGADOR_H
#define JUGADOR_H
#include <QPainter>

class Jugador
{
private:
    int x, y;
    int ancho, alto;
    int vida;
    bool vivo;
    int numero;
public:
    Jugador();
    Jugador(int x, int y, int ancho, int alto, int numero);
    bool colisiona(float px, float py, float rad);
    void dibujar(QPainter& painter);
    bool estaVivo() const { return vivo; }
    void morir() {vivo = false;}
    int getNumero() const {return numero;}
    int getx()const{return x;}
    int gety()const{return y;}
};

#endif // JUGADOR_H
