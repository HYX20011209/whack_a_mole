#include "chooselevelscene.h"
#include <QMenuBar>
#include <QPainter>
#include "mypushbutton.h"
#include <QDebug>
#include <QTimer>
#include <QLabel>
#include<QMessageBox>
ChooseLevelScene::ChooseLevelScene(QWidget *parent) : QMainWindow(parent)
{
    //设置音效
    QSound* clickSound = new QSound(":/new/prefix4/sound02/TapButtonSound.wav",this);
    QSound* backSound = new QSound(":/new/prefix4/sound02/BackButtonSound.wav",this);
    //配置选择关卡场景
    this->setFixedSize(1000,700);

    //设置图标
    this->setWindowIcon(QPixmap(":/new/prefix1/Image/mouse_2.png"));

    //设置标题
    this->setWindowTitle("ChooseLevel");

    //创建菜单栏
    QMenuBar * bar = menuBar();
    setMenuBar(bar);

    //创建开始菜单
    QMenu * startMenu = bar->addMenu("Menu");

    //创建退出 菜单项
    QAction *  quitAction = startMenu->addAction("Quit");

    //点击退出 实现退出游戏
    connect(quitAction,&QAction::triggered,[=](){
        this->close();
    });
    QAction *helpAction=startMenu->addAction("Help");
    connect(helpAction,&QAction::triggered,[=](){
        QMessageBox::information(this,"info","玩家通过点击屏幕上出现的地鼠使其消失，玩家可以选择游戏的难度，难度越大，单位时间内出现的地鼠也就越多！");
    });


    //返回按钮
    MyPushButton * backBtn = new MyPushButton(":/new/prefix2/backbtn/BackButton.png" , ":/new/prefix2/backbtn/BackButtonSelected.png");
    backBtn->setParent(this);
    backBtn->move(this->width() - backBtn->width() , this->height() - backBtn->height());

    //点击返回
    connect(backBtn,&MyPushButton::clicked,[=](){
        //延时返回
        backSound->play();
        QTimer::singleShot(500,this,[=](){
            emit this->chooseSceneBack();
        });

    });

    MyPushButton * Btn1 = new MyPushButton(":/new/prefix1/Image/blue_button00.png" , ":/new/prefix1/Image/blue_button01.png");
    Btn1->setParent(this);
    Btn1->move(this->width()*0.5-Btn1->width()*0.5,this->height()*0.3);
    connect(Btn1,&MyPushButton::clicked,[=](){

        clickSound->play();
        //进入到游戏场景
        this->hide(); //将选关场景隐藏掉
        play = new PlayScene(1); //创建游戏场景
        play->show();//显示游戏场景

        connect(play,&PlayScene::chooseSceneBack,[=](){
            this->show();
            delete play;
            play = NULL;
        });

    });


    MyPushButton * Btn2 = new MyPushButton(":/new/prefix1/Image/green_button00.png" , ":/new/prefix1/Image/green_button01.png");
    Btn2->setParent(this);
    Btn2->move(this->width()*0.5-Btn2->width()*0.5,this->height()*0.45);

    connect(Btn2,&MyPushButton::clicked,[=](){
        clickSound->play();
        //进入到游戏场景
        this->hide(); //将选关场景隐藏掉
        play = new PlayScene(2); //创建游戏场景
        play->show();//显示游戏场景

        connect(play,&PlayScene::chooseSceneBack,[=](){
            this->show();
            delete play;
            play = NULL;

        });

    });

    MyPushButton * Btn3 = new MyPushButton(":/new/prefix1/Image/red_button00.png" , ":/new/prefix1/Image/red_button01.png");
    Btn3->setParent(this);
    Btn3->move(this->width()*0.5-Btn3->width()*0.5,this->height()*0.6);

    connect(Btn3,&MyPushButton::clicked,[=](){
        clickSound->play();
        //进入到游戏场景
        this->hide(); //将选关场景隐藏掉
        play = new PlayScene(3); //创建游戏场景
        play->show();//显示游戏场景

        connect(play,&PlayScene::chooseSceneBack,[=](){
            this->show();
            delete play;
            play = NULL;

        });

    });



}


void ChooseLevelScene::paintEvent(QPaintEvent *)
{
    //加载背景
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/new/prefix1/Image/background1.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);



}
