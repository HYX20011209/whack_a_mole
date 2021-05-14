#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include <QMainWindow>
#include<QPushButton>
#include<QTimer>
#include<QLCDNumber>
#include<QSound>
class PlayScene : public QMainWindow
{
    Q_OBJECT
public:
//    explicit PlayScene(QWidget *parent = nullptr);

    PlayScene(int levelNum);    //关卡难度数
    int levelIndex;

    int status[12];
    int score{0};
    //地鼠每次持续出现的时间
    int OneTime{2};
    //一局游戏的时间,秒为单位
    int GameTime{10};
    //计算刷新地图的次数，用于计时器的lcd显示
    int count{GameTime};

    //游戏时间计时器
    QTimer* GameTimer = new QTimer(this);
    //刷新地图计时器
    QTimer* refreshTimer = new QTimer(this);
    //显示器
    QLCDNumber *lcdscore=new QLCDNumber(this);
    QLCDNumber *lcdTime=new QLCDNumber(this);
    //音效
    QSound* player1 = new QSound(":/new/prefix3/sound/backsound.wav");


    //set mousebuttons
    QPushButton *p1=new QPushButton(this);
    QPushButton *p2=new QPushButton(this);
    QPushButton *p3=new QPushButton(this);
    QPushButton *p4=new QPushButton(this);
    QPushButton *p5=new QPushButton(this);
    QPushButton *p6=new QPushButton(this);
    QPushButton *p7=new QPushButton(this);
    QPushButton *p8=new QPushButton(this);
    QPushButton *p9=new QPushButton(this);
    QPushButton *p10=new QPushButton(this);
    QPushButton *p11=new QPushButton(this);
    QPushButton *p12=new QPushButton(this);

    void paintEvent(QPaintEvent*);


    //按钮矩阵中，按钮点击的回应函数
    void hit(int& status, QPushButton*);

    //对启动计时器，开始游戏
    void startGame();

    //设计老鼠一次出现的持续时间
    void setOneTime(int );

    //设置一局游戏的时间
    void setGameTime(int );

    //在窗口实时更新游戏分数
    void updateScore();
    //score变量的get函数
    int getScore();



    ~PlayScene();

signals:
    //返回信号
    void chooseSceneBack();

private slots:
    void on_p1_clicked();
    void on_p2_clicked();
    void on_p3_clicked();
    void on_p4_clicked();
    void on_p5_clicked();
    void on_p6_clicked();
    void on_p7_clicked();
    void on_p8_clicked();
    void on_p9_clicked();
    void on_p10_clicked();
    void on_p11_clicked();
    void on_p12_clicked();


    //刷新计时器槽函数
    void timeOutRefresh();
    void timeOutClose();

    void newMap();//刷新地图，主要是对status数组的刷新和按钮形状的刷新


};

#endif // PLAYSCENE_H
