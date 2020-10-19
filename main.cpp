#include "miniwidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    miniWidget w;
    w.show();
    return a.exec();
}
