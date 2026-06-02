#ifndef WIDGET_COLSIONES_H
#define WIDGET_COLSIONES_H

#include <QWidget>
#include <QTimer>
#include <QVector>
#include "pelota.h"
#include "cajas_c.h"

class widget_colsiones : public QWidget
{
    Q_OBJECT
public:
    explicit widget_colsiones(QWidget *parent = nullptr);
    void agregarPelota(int x,int y,int velx,int vely,int rad);
    void agregarcaja(int x,int y,int ancho,int alto);
    void detectarcolision();
    widget_colsiones();
protected:
    void paintEvent(QPaintEvent *event);
private slots:
    void actualizar();

private:
    QTimer *timer;
    QVector<Pelota> pelotas;
    QVector<cajas_c> cajas;
};

#endif // WIDGET_COLSIONES_H
