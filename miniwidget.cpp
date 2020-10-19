#include "miniwidget.h"
#include "ui_miniwidget.h"

miniWidget::miniWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::miniWidget)
{
    ui->setupUi(this);

    setWindowFlags(Qt::Widget | Qt::FramelessWindowHint);
}

miniWidget::~miniWidget()
{
    delete ui;
}

void miniWidget::disconnections()
{
    connect(ui->tabWidget, &QTabWidget::currentChanged, this, &miniWidget::tab_change);
}

void miniWidget::connections()
{

}




void miniWidget::on_pushButton_clicked()
{

}

void miniWidget::on_pushButton_2_clicked()
{

}


void miniWidget::show_all_orders()
{
    qDebug () << "Hello1";
    foreach (currentTableWidget, ui->tableWidget_allOrders->findChildren<QTableWidget*>())
    {
        currentTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        currentTableWidget->setColumnCount(9);

        currentTableWidget->setHorizontalHeaderLabels(QStringList() << "Mobilya Kodu" << "Talep Eden Kurum" <<"Adet" << "Teslim Tarihi" << "Sabit" <<"Periyot" <<"id" <<"criteriaEvaluationTypeId" << "criteriaId");

        currentTableWidget->horizontalHeader()->resizeSection(0, 50);
        currentTableWidget->horizontalHeader()->resizeSection(1, 590);
        currentTableWidget->horizontalHeader()->resizeSection(2, 190);
        currentTableWidget->horizontalHeader()->resizeSection(3, 190);
        currentTableWidget->horizontalHeader()->resizeSection(4, 160);
        currentTableWidget->horizontalHeader()->resizeSection(5, 100);
        currentTableWidget->horizontalHeader()->resizeSection(6, 0);
        currentTableWidget->horizontalHeader()->resizeSection(7, 0);
        currentTableWidget->horizontalHeader()->resizeSection(8, 0);

        currentTableWidget->verticalHeader()->setDefaultSectionSize(40);

        currentTableWidget->setSortingEnabled(true);

        while (currentTableWidget->rowCount() > 0)
        {
            currentTableWidget->removeRow(0);
        }
    }
    qDebug() << "Hello2";

    QString sutun1 = "Hello";
    QString sutun2 = "World.";
    QString upArea = "uparea";
    QString downArea = "uparea";
    QString constant = "uparea";
    QString periodic = "uparea";
    int id = 1;
    int sutun3 = 2;
    int criteriaId = 3;

    static QTableWidgetItem *item;
    currentTableWidget->insertRow(2);

//    item = new QTableWidgetItem(sutun1);
//    item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled|Qt::ItemIsUserCheckable);
//    item->setTextAlignment(Qt::AlignCenter | Qt::AlignVCenter);
//    currentTableWidget->setItem(currentTableWidget->rowCount() - 1, 0, item);
//    currentTableWidget->setCellWidget(currentTableWidget->rowCount()-1, 0, checkBox);

    item = new QTableWidgetItem(sutun2);
    item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    item->setTextAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    currentTableWidget->setItem(currentTableWidget->rowCount() - 1, 1, item);

    item = new QTableWidgetItem(upArea);
    item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    currentTableWidget->setItem(currentTableWidget->rowCount() - 1, 2, item);

    item=new QTableWidgetItem(downArea);
    item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    currentTableWidget->setItem(currentTableWidget->rowCount() - 1, 3, item);

    item = new QTableWidgetItem(constant);
    item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    currentTableWidget->setItem(currentTableWidget->rowCount() - 1, 4, item);

    item = new QTableWidgetItem(periodic);
    item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    item->setTextAlignment(Qt::AlignCenter | Qt::AlignVCenter);
    currentTableWidget->setItem(currentTableWidget->rowCount() - 1, 5, item);

    item=new QTableWidgetItem(QString::number(id));
    item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    item->setTextAlignment(Qt::AlignCenter);
    currentTableWidget->setItem(currentTableWidget->rowCount() - 1, 6, item);

    item = new QTableWidgetItem(QString::number(sutun3));
    item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    item->setTextAlignment(Qt::AlignCenter);
    currentTableWidget->setItem(currentTableWidget->rowCount() - 1, 7, item);

    item = new QTableWidgetItem(QString::number(criteriaId));
    item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    item->setTextAlignment(Qt::AlignCenter);
    currentTableWidget->setItem(currentTableWidget->rowCount() - 1, 8, item);

}



void miniWidget::on_btn_close_clicked()
{
    this->close();
}

void miniWidget::tab_change(int index)
{
    if(index == 1){
        show_all_orders();
    }
}
