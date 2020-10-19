#ifndef MINIWIDGET_H
#define MINIWIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class miniWidget; }
QT_END_NAMESPACE

class miniWidget : public QWidget
{
    Q_OBJECT

public:
    miniWidget(QWidget *parent = nullptr);
    ~miniWidget();

private:
    Ui::miniWidget *ui;
};
#endif // MINIWIDGET_H
