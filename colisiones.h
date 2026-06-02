#ifndef COLISIONES_H
#define COLISIONES_H
#include "widget_colsiones.h"

#include <QWidget>

namespace Ui {
class colisiones;
}

class colisiones : public QWidget
{
    Q_OBJECT
signals:
    void volver();
private slots:
    void botonVolver();
public:
    explicit colisiones(QWidget *parent = nullptr);
    ~colisiones();

private:
   // widget_colsiones simulacion;
    Ui::colisiones *ui;
};

#endif // COLISIONES_H
