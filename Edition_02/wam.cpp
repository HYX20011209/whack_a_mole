#include "wam.h"
#include "ui_wam.h"
#include<QPainter>
#include<QPixmap>
#include"mypushbutton.h"
#include<QPushButton>
#include<QTimer>
#include<QDebug>
#include<QSound>
#include<QMessageBox>
Wam::Wam(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Wam)
{
    ui->setupUi(this);

    this->setFixedSize(1000,700);       //set size
    this->setWindowIcon(QPixmap(":/new/prefix1/Image/mouse_1.png"));   //set logo
    this->setWindowTitle("whack-a-mole");    //set Title

    //设置音效
    QSound* clickSound = new QSound(":/new/prefix4/sound02/TapButtonSound.wav",this);

    //创建菜单栏
    QMenuBar * bar = menuBar();
    setMenuBar(bar);

    //创建开始菜单
    QMenu * startMenu = bar->addMenu("Menu");

    //创建退出菜单项
    QAction *  quitAction = startMenu->addAction("Quit");

    //点击退出 实现退出游戏
    connect(quitAction,&QAction::triggered,[=](){
        this->close();
    });

    //帮助文档
    QAction *helpAction=startMenu->addAction("Help");
    connect(helpAction,&QAction::triggered,[=](){
        QMessageBox::information(this,"info","玩家通过点击屏幕上出现的地鼠使其消失，玩家可以选择游戏的难度，难度越大，单位时间内出现的地鼠也就越多！");
    });


    MyPushButton * startBtn = new MyPushButton(":/new/prefix1/Image/MenuSceneStartButton.png");
    startBtn->setParent(this);
    startBtn->move(this->width()*0.5-startBtn->width()*0.5,this->height()*0.55);

    //实例化选择关卡场景
    chooseScene = new ChooseLevelScene;
    connect(chooseScene,&ChooseLevelScene::chooseSceneBack,this,[=](){
        chooseScene->hide(); //将选择关卡场景 隐藏掉
        this->show(); //重新显示主场景
    });


    connect(startBtn,&MyPushButton::clicked,[=](){
        //qDebug() << "点击了开始";
        //做弹起特效
        clickSound->play();

        startBtn->down();
        startBtn->up();

        //延时进入到选择关卡场景中
        QTimer::singleShot(300,this,[=](){
            //自身隐藏
            this->hide();
            //显示选择关卡场景
            chooseScene->show();
        });

    });
}

void Wam::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/new/prefix1/Image/background1.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    QPixmap pix1;
    pix1.load(":/new/prefix1/Image/mouse_1.png");
    painter.drawPixmap(100,170,150,150,pix1);
    QPixmap pix2;
    pix2.load(":/new/prefix1/Image/mouse_2.png");
    painter.drawPixmap(400,60,150,150,pix2);

    QPixmap pix3;
    pix3.load(":/new/prefix1/Image/mouse_3.png");
    painter.drawPixmap(680,460,150,150,pix3);


}

Wam::~Wam()
{
    delete ui;
}
