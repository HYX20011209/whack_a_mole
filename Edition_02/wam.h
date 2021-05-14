#ifndef WAM_H
#define WAM_H

#include <QMainWindow>
#include "chooselevelscene.h"
QT_BEGIN_NAMESPACE
namespace Ui { class Wam; }
QT_END_NAMESPACE

class Wam : public QMainWindow
{
    Q_OBJECT

public:
    Wam(QWidget *parent = nullptr);
    ~Wam();
    void paintEvent(QPaintEvent *);
    ChooseLevelScene * chooseScene = NULL;



private:
    Ui::Wam *ui;
};
#endif // WAM_H
