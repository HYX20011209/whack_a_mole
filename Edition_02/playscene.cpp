#include "playscene.h"
#include<QDebug>
#include<QMenuBar>
#include <QPainter>
#include "mypushbutton.h"
#include <QTimer>
#include <QLabel>
#include<QPushButton>
#include<QPixmap>
#include<QMessageBox>
//PlayScene::PlayScene(QWidget *parent) : QMainWindow(parent)
//{

//}


PlayScene::PlayScene(int levelNum)
{
    QString str = QString("进入了第 %1 关 ").arg(levelNum);
    qDebug() << str;
    this->levelIndex = levelNum;

    //初始化游戏场景

    QSound* backSound = new QSound(":/new/prefix4/sound02/BackButtonSound.wav",this);
    //设置固定大小
    this->setFixedSize(1000,700);
    //设置图标
    this->setWindowIcon(QPixmap(":/new/prefix1/Image/mouse_3.png"));
    //设置标题
    this->setWindowTitle("PLAY!");

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

        backSound->play();
        QTimer::singleShot(500,this,[=](){
            player1->stop();
            emit this->chooseSceneBack();
        });

    });


    //显示当前关卡数
    QLabel * label = new QLabel;
    label->setParent(this);
    QFont font;
    font.setFamily("华文新魏");
    font.setPointSize(20);
    QString str1 = QString("Level: %1").arg(this->levelIndex);
    //将字体设置到标签控件中
    label->setFont(font);
    label->setText( str1);
    label->setGeometry(30, this->height() - 50,120, 50);


    //显示分数栏
    QLabel *scoreLabel =new QLabel;
    scoreLabel->setParent(this);
    QFont scoreFont;
    scoreFont.setFamily("华文新魏");
    scoreFont.setPointSize(25);
    scoreLabel->setFont(scoreFont);
    scoreLabel->setText("Score:");
    scoreLabel->setGeometry(150,45,120,50);

    //显示时间栏
    QLabel *timeLabel =new QLabel;
    timeLabel->setParent(this);
    QFont timeFont;
    timeFont.setFamily("华文新魏");
    timeFont.setPointSize(25);
    timeLabel->setFont(timeFont);
    timeLabel->setText("Time:");
    timeLabel->setGeometry(650,45,120,50);


    //在显示器中显示当前分数
    lcdscore->resize(200,60);
    lcdscore->move(300,40);

    //在显示器中显示当前剩余时间
    lcdTime->resize(200,60);
    lcdTime->move(this->width()-lcdscore->width(),40);


    //设置按钮大小、位置，连接信号槽
    QSize holesize(120,120);
    p1->setIconSize(holesize);
    p1->resize(120,120);
    p1->move(120+200*0,130+160*0);
    connect(p1,&QPushButton::clicked,this,&PlayScene::on_p1_clicked);

    p2->setIconSize(holesize);
    p2->resize(120,120);
    p2->move(120+200*1,130+160*0);
    connect(p2,&QPushButton::clicked,this,&PlayScene::on_p2_clicked);


    p3->setIconSize(holesize);
    p3->resize(120,120);
    p3->move(120+200*2,130+160*0);
    connect(p3,&QPushButton::clicked,this,&PlayScene::on_p3_clicked);


    p4->setIconSize(holesize);
    p4->resize(120,120);
    p4->move(120+200*3,130+160*0);
    connect(p4,&QPushButton::clicked,this,&PlayScene::on_p4_clicked);


    p5->setIconSize(holesize);
    p5->resize(120,120);
    p5->move(120+200*0,130+160*1);
    connect(p5,&QPushButton::clicked,this,&PlayScene::on_p5_clicked);


    p6->setIconSize(holesize);
    p6->resize(120,120);
    p6->move(120+200*1,130+160*1);
    connect(p6,&QPushButton::clicked,this,&PlayScene::on_p6_clicked);


    p7->setIconSize(holesize);
    p7->resize(120,120);
    p7->move(120+200*2,130+160*1);
    connect(p7,&QPushButton::clicked,this,&PlayScene::on_p7_clicked);


    p8->setIconSize(holesize);
    p8->resize(120,120);
    p8->move(120+200*3,130+160*1);
    connect(p8,&QPushButton::clicked,this,&PlayScene::on_p8_clicked);


    p9->setIconSize(holesize);
    p9->resize(120,120);
    p9->move(120+200*0,130+160*2);
    connect(p9,&QPushButton::clicked,this,&PlayScene::on_p9_clicked);


    p10->setIconSize(holesize);
    p10->resize(120,120);
    p10->move(120+200*1,130+160*2);
    connect(p10,&QPushButton::clicked,this,&PlayScene::on_p10_clicked);


    p11->setIconSize(holesize);
    p11->resize(120,120);
    p11->move(120+200*2,130+160*2);
    connect(p11,&QPushButton::clicked,this,&PlayScene::on_p11_clicked);


    p12->setIconSize(holesize);
    p12->resize(120,120);
    p12->move(120+200*3,130+160*2);
    connect(p12,&QPushButton::clicked,this,&PlayScene::on_p12_clicked);

    //根据选择关卡难度调整每次地鼠出现的时间间隔
    if(levelIndex==1)setOneTime(3);
    if(levelIndex==2)setOneTime(2);
    if(levelIndex==3)setOneTime(1);



    refreshTimer->connect(refreshTimer,SIGNAL(timeout()),this,SLOT(timeOutRefresh()));
    GameTimer->connect(GameTimer,SIGNAL(timeout()),this,SLOT(timeOutClose()));

    startGame();
}


void PlayScene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;

    //打印背景图
    pix.load(":/new/prefix1/Image/background1.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

}


void PlayScene::newMap()
{

    //刷新地图
    memset(status,0,11*sizeof(int));
    p1->hide();p2->hide();p3->hide();p4->hide();p5->hide();p6->hide();p7->hide();p8->hide();p9->hide();p10->hide();p11->hide();p12->hide();
    //取消按钮边框
    p1->setStyleSheet("QPushButton{border:0px;}");
    p2->setStyleSheet("QPushButton{border:0px;}");
    p3->setStyleSheet("QPushButton{border:0px;}");
    p4->setStyleSheet("QPushButton{border:0px;}");
    p5->setStyleSheet("QPushButton{border:0px;}");
    p6->setStyleSheet("QPushButton{border:0px;}");
    p7->setStyleSheet("QPushButton{border:0px;}");
    p8->setStyleSheet("QPushButton{border:0px;}");
    p9->setStyleSheet("QPushButton{border:0px;}");
    p10->setStyleSheet("QPushButton{border:0px;}");
    p11->setStyleSheet("QPushButton{border:0px;}");
    p12->setStyleSheet("QPushButton{border:0px;}");

    std::srand(time(0));//生成时间种子
    int rand1=12;
    int rand2=12;

    for(int i=0;i<levelIndex+2;i++)
    {
        rand1=rand()%10;//生成0-9的随机数
        rand2=rand()%12;//生成0-11的随机数


        switch(rand2)
        {
        case 0:
        {
            if(rand1<3)status[0]=0;
            else{p1->show();p1->setIcon(QIcon(":/new/prefix1/Image/mouse_1.png"));  status[0]=1;}
            break;
        }
        case 1:
        {
            if(rand1<3)status[1]=0;
            else{p2->show();p2->setIcon(QIcon(":/new/prefix1/Image/mouse_1.png"));  status[1]=1;}
            break;
        }
        case 2:
        {
            if(rand1<3)status[2]=0;
            else{p3->show();p3->setIcon(QIcon(":/new/prefix1/Image/mouse_1.png"));  status[2]=1;}
            break;
        }
        case 3:
        {
            if(rand1<3)status[3]=0;
            else{p4->show();p4->setIcon(QIcon(":/new/prefix1/Image/mouse_1.png"));  status[3]=1;}
            break;
        }
        case 4:
        {
            if(rand1<3)status[4]=0;
            else{p5->show();p5->setIcon(QIcon(":/new/prefix1/Image/mouse_1.png"));  status[4]=1;}
            break;
        }
        case 5:
        {
            if(rand1<3)status[5]=0;
            else{p6->show();p6->setIcon(QIcon(":/new/prefix1/Image/mouse_1.png"));  status[5]=1;}
            break;
        }
        case 6:
        {
            if(rand1<3)status[6]=0;
            else{p7->show();p7->setIcon(QIcon(":/new/prefix1/Image/mouse_1.png"));  status[6]=1;}
            break;
        }
        case 7:
        {
            if(rand1<3)status[7]=0;
            else{p8->show();p8->setIcon(QIcon(":/new/prefix1/Image/mouse_1.png"));  status[7]=1;}
            break;
        }
        case 8:
        {
            if(rand1<3)status[8]=0;
            else{p9->show();p9->setIcon(QIcon(":/new/prefix1/Image/mouse_1.png"));  status[8]=1;}
            break;
        }
        case 9:
        {
            if(rand1<3)status[9]=0;
            else{p10->show();p10->setIcon(QIcon(":/new/prefix1/Image/mouse_1.png"));  status[9]=1;}
            break;
        }
        case 10:
        {
            if(rand1<3)status[10]=0;
            else{p11->show();p11->setIcon(QIcon(":/new/prefix1/Image/mouse_1.png"));  status[10]=1;}
            break;
        }
        case 11:
        {
            if(rand1<3)status[11]=0;
            else{p12->show();p12->setIcon(QIcon(":/new/prefix1/Image/mouse_1.png"));  status[11]=1;}
            break;
        }
        default:break;
        }
    }

}

//更新分数
void PlayScene::updateScore(){
    lcdscore->display(score);
}

void PlayScene::startGame()
{
    score=0;
    updateScore();
    timeOutClose();
    newMap();
    //游戏计时
    GameTimer->start(1000);

    //刷新计时
    refreshTimer->start(OneTime*1000);
    //播放音乐
    player1->setLoops(QSound::Infinite);
    player1->play();
}

void PlayScene::timeOutClose()
{
    lcdTime->display(count);
    count--;
    if(count<0)
    {
        refreshTimer->stop();
        GameTimer->stop();
        player1->stop();
        QSound *endSound=new QSound(":/new/prefix3/sound/victory.wav");
        endSound->play();

        QFont endFont;
        endFont.setFamily("宋体");
        endFont.setPointSize(20);
        QString endstr = QString("您在第 %1 关获得的分数是: %2").arg(this->levelIndex).arg(this->score);

        QMessageBox* Box=new QMessageBox(this);
        Box->setBackgroundRole(QPalette::Text);
        Box->setFont(endFont);
        Box->setText(endstr);
        Box->show();
    }
}



//score函数获取函数
int PlayScene::getScore(){
    return score;
}
//游戏时间set函数
void PlayScene::setGameTime(int time){
    this->GameTime=time;
}

//老鼠一次出现的时间set函数
void PlayScene::setOneTime(int oneTime){
    this->OneTime=oneTime;
}
void  PlayScene::hit(int& st, QPushButton* btn)
{
    if(st==0){}
    else if(st==1)
    {
        btn->hide();
        this->score+=10;
    }
    st=0;
    updateScore();
}


//刷新地图机器是的槽函数
void PlayScene ::timeOutRefresh()
{
    newMap();
}
void PlayScene::on_p1_clicked()
{
    hit(status[0],p1);
}
void PlayScene::on_p2_clicked()
{
    hit(status[1],p2);
}
void PlayScene::on_p3_clicked()
{
    hit(status[2],p3);
}
void PlayScene::on_p4_clicked()
{
    hit(status[3],p4);
}
void PlayScene::on_p5_clicked()
{
    hit(status[4],p5);
}
void PlayScene::on_p6_clicked()
{
    hit(status[5],p6);
}
void PlayScene::on_p7_clicked()
{
    hit(status[6],p7);
}
void PlayScene::on_p8_clicked()
{
    hit(status[7],p8);
}
void PlayScene::on_p9_clicked()
{
    hit(status[8],p9);
}
void PlayScene::on_p10_clicked()
{
    hit(status[9],p10);
}
void PlayScene::on_p11_clicked()
{
    hit(status[10],p11);
}
void PlayScene::on_p12_clicked()
{
    hit(status[11],p12);
}


PlayScene::~PlayScene()
{
    delete GameTimer;
    delete refreshTimer;
}
