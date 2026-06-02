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
private slots:
    void botonvolver();
public:
    explicit proyectiles(QWidget *parent = nullptr);
    ~proyectiles();
private:
    Ui::proyectiles *ui;
};

#endif // PROYECTILES_H
