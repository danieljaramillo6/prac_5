#include "proyectiles.h"
#include "ui_proyectiles.h"
#include "pelota.h"

proyectiles::proyectiles(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::proyectiles)
{
    jug1=Jugador(120,450,20,20,1);
    jug2=Jugador(620,450,20,20,2);
    potencia = 15;
    ui->setupUi(this);
    connect(ui->botonsalir,&QPushButton::clicked,this,&proyectiles::botonvolver);
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &proyectiles::onTimer);
    timer->start(16);
    pelota=Pelota(30,100,0,0,10,10);
    agregarcaja(100,400,100,20,100);
    agregarcaja(150,400,100,20,100);
    agregarcaja(100,380,20,70,200);
    agregarcaja(600,400,100,20,100);
    agregarcaja(650,400,100,20,100);
    agregarcaja(600,380,20,70,200);
    jugada=false;
    jugador=false;
    ganador=0;
}

void proyectiles::mousePressEvent(QMouseEvent* event){
    float dx = event->pos().x() - pelota.getx();
    float dy = event->pos().y() - pelota.gety();
    float angulo = atan2(dy, dx);

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
            pelota.revivir();
            jugador=false;
        }
        else {
            pelota.setpos(700,100);
            pelota.revivir();
            jugador=true;
        }
        jugada=false;
    }
    for(int i = cajas.size()-1; i >= 0; i--){
        if(cajas[i].getVida() <= 0){
            cajas.erase(cajas.begin() + i);
        }
    }
    if(jugador){
        if(jug2.colisiona(pelota.getx(), pelota.gety(), pelota.getrad())){
            jug2.morir();
            juego_terminado = true;
            ganador=1;
        }
    } else {
        if(jug1.colisiona(pelota.getx(), pelota.gety(), pelota.getrad())){
            jug1.morir();
            juego_terminado = true;
            ganador=2;
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
    jug1.dibujar(painter);
    jug2.dibujar(painter);
    if(juego_terminado){
        painter.setPen(Qt::black);
        painter.setFont(QFont("Arial", 30, QFont::Bold));
        painter.drawText(width()/2 - 100, height()/2, "Gana jugador " + QString::number(ganador));
}
}





void proyectiles::on_horizontalSlider_valueChanged(int value)
{
    potencia=value;
}

