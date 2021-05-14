#include "wam.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Wam w;
    w.show();
    return a.exec();
}
