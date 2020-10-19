#include "miniwidget.h"
#include "ui_miniwidget.h"

miniWidget::miniWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::miniWidget)
{
    ui->setupUi(this);
}

miniWidget::~miniWidget()
{
    delete ui;
}

