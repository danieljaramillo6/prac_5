#ifndef PROYECTILES_H
#define PROYECTILES_H

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
    explicit widget_colsiones(QWidget *parent = nullptr);
    void agregarPelota(int x,int y,int velx,int vely,int rad);
    void agregarcaja(int x,int y,int ancho,int alto);
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

#endif // PROYECTILES_H
