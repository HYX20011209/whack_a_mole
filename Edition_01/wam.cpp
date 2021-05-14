#include "wam.h"
#include "ui_wam.h"
#include<QPainter>
#include<QPixmap>
#include"mypushbutton.h"
#include<QPushButton>
Wam::Wam(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Wam)
{
    ui->setupUi(this);

    this->setFixedSize(1000,700);       //set size
    this->setWindowIcon(QPixmap(":/new/prefix1/Image/mouse_1.png"));   //set logo
    this->setWindowTitle("whack-a-mole");    //set Title

    MyPushButton * startBtn = new MyPushButton(":/startbtn/MenuSceneStartButton.png");
    startBtn->setParent(this);
    startBtn->move(this->width()*0.5-startBtn->width()*0.5,this->height()*0.7);

    connect(startBtn,&MyPushButton::clicked,[=](){
        //qDebug() << "点击了开始";
        //做弹起特效
        startBtn->zoom1();
        startBtn->zoom2();
    });

    MyPushButton * startBtn1 = new MyPushButton(":/new/prefix2/bottons_01/PNG/red_button01.png");
    startBtn1->setParent(this);
    startBtn1->move(this->width()*0.5-startBtn1->width()*0.5,this->height()*0.3);
    connect(startBtn1,&MyPushButton::clicked,[=](){
        //qDebug() << "点击了开始";
        //做弹起特效
        startBtn1->zoom1();
        startBtn1->zoom2();
    });


    MyPushButton * startBtn2 = new MyPushButton(":/new/prefix2/bottons_01/PNG/green_button00.png");
    startBtn2->setParent(this);
    startBtn2->move(this->width()*0.5-startBtn2->width()*0.5,this->height()*0.45);

    connect(startBtn2,&MyPushButton::clicked,[=](){
        //qDebug() << "点击了开始";
        //做弹起特效
        startBtn2->zoom1();
        startBtn2->zoom2();
    });

    MyPushButton * startBtn3 = new MyPushButton(":/new/prefix2/bottons_01/PNG/blue_button00.png");
    startBtn3->setParent(this);
    startBtn3->move(this->width()*0.5-startBtn3->width()*0.5,this->height()*0.6);

    connect(startBtn3,&MyPushButton::clicked,[=](){
        //qDebug() << "点击了开始";
        //做弹起特效
        startBtn3->zoom1();
        startBtn3->zoom2();
    });

}

void Wam::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/new/prefix1/Image/background.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

}

Wam::~Wam()
{
    delete ui;
}

