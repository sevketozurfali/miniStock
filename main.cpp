#include "miniwidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    miniWidget w;
    w.showMaximized();
    return a.exec();
}

void QWidget::showMaximized(){
    setWindowState((windowState() &~(Qt::WindowMinimized | Qt::WindowFullScreen)) | Qt::WindowMaximized);
    show();
}
