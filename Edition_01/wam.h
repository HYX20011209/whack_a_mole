#ifndef WAM_H
#define WAM_H

#include <QMainWindow>

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

private:
    Ui::Wam *ui;
};
#endif // WAM_H
