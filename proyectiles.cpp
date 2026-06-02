#include "proyectiles.h"
#include "ui_proyectiles.h"
#include "pelota.h"

proyectiles::proyectiles(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::proyectiles)
{
    ui->setupUi(this);
    connect(ui->botonsalir,&QPushButton::clicked,this,&proyectiles::botonvolver);
    timer = new QTimer(this);  // ← falta esto
    connect(timer, &QTimer::timeout, this, &proyectiles::onTimer);
    timer->start(16);
    pelota=Pelota(30,100,0,0,10,10);
    agregarcaja(50,300,50,50,100);
    jugada=false;
    jugador=true;
}

void proyectiles::mousePressEvent(QMouseEvent* event){
    float dx = event->pos().x() - pelota.getx();
    float dy = event->pos().y() - pelota.gety();
    float angulo = atan2(dy, dx);

    float potencia = 15.0f;

    pelota.setVelx(potencia * cos(angulo));
    pelota.setVely(potencia * sin(angulo));
    jugada=true;
}

proyectiles::~proyectiles()
{
    delete ui;
}

void proyectiles::onTimer(){
    if (!jugada)return;
    pelota.mover2(width(),height(),cajas);
    if (!pelota.getviva()){
        if (jugador){
            pelota.setpos(30,100);
            jugador=false;
        }
        else {
            pelota.setpos(300,100);
            jugador=true;
        }
        jugada=false;
    }
    for(int i = cajas.size()-1; i >= 0; i--){
        if(cajas[i].getVida() <= 0){
            cajas.erase(cajas.begin() + i);
        }
    }
    update();
}

void proyectiles::botonvolver(){
    emit volver();
}

void proyectiles::agregarcaja(int x, int y, int ancho, int alto,int vida){
    cajas.push_back(cajas_p(x,y,ancho,alto,vida));
}

void proyectiles::paintEvent(QPaintEvent* event){
    QPainter painter(this);
    pelota.dibujar(painter);
    for(int i = 0; i < cajas.size(); i++){
        cajas[i].dibujar(painter);
        painter.setPen(Qt::white);
        painter.setFont(QFont("Arial", 12, QFont::Bold));
        painter.drawText(cajas[i].getx(), cajas[i].gety(), cajas[i].getancho(), cajas[i].getalto(),Qt::AlignCenter,QString::number(cajas[i].getVida()));
}
}


