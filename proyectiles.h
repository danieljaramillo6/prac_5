#ifndef PROYECTILES_H
#define PROYECTILES_H
#include "cajas_p.h"
#include "pelota.h"
#include <QTimer>
#include <QMouseEvent>
#include "jugador.h"
#include <QWidget>

namespace Ui {
class proyectiles;
}

class proyectiles : public QWidget
{
    Q_OBJECT
signals:
    void volver();
public:
    proyectiles(QWidget* parent = nullptr);
    ~proyectiles();

    void agregarPelota(int x,int y,int velx,int vely,int rad);
    void agregarcaja(int x,int y,int ancho,int alto,int vida);

protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent* event) override;
private slots:
    void onTimer();
    void botonvolver();

    void on_horizontalSlider_actionTriggered(int action);

    void on_horizontalSlider_valueChanged(int value);

private:
    Ui::proyectiles* ui;
    QTimer *timer;
    QVector<cajas_p> cajas;
    Pelota pelota;
    bool jugada;
    bool jugador;
    int potencia;
    Jugador jug1;
    Jugador jug2;
    bool juego_terminado;
    int ganador;
};

#endif // PROYECTILES_H
