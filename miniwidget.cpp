#include "miniwidget.h"
#include "ui_miniwidget.h"

miniWidget::miniWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::miniWidget)
{
    ui->setupUi(this);

    setWindowFlags(Qt::Widget | Qt::FramelessWindowHint);

    initilization();
}

miniWidget::~miniWidget()
{
    delete ui;
}

void miniWidget::initilization()
{
    disconnections();
    connections();

    currentTableWidget = NULL;

    ui->tabWidget->setTabText(0, "Sipariş");
    ui->tabWidget->setTabText(1, "İzleme");
    ui->tabWidget->setCurrentIndex(0);
}

void miniWidget::sqlLiteDatabase_initilization()
{
    const QString DRIVER("QSLITE");

    if(QSqlDatabase::isDriverAvailable(DRIVER)){
        QSqlDatabase db = QSqlDatabase::addDatabase(DRIVER);
        db.setDatabaseName(":memory:");
        if(!db.open()){
            qWarning() << "Error! : " << db.lastError();
        }
    }

}

void miniWidget::disconnections()
{
    disconnect(ui->tabWidget, &QTabWidget::currentChanged, this, &miniWidget::tab_change);


}

void miniWidget::connections()
{
    connect(ui->tabWidget, &QTabWidget::currentChanged, this, &miniWidget::tab_change);
}

void miniWidget::on_pushButton_clicked()
{

}

void miniWidget::on_pushButton_2_clicked()
{

}


void miniWidget::show_all_orders()
{

    currentTableWidget = new QTableWidget();
    currentTableWidget->setParent(ui->tab_list_all);

    foreach (currentTableWidget, ui->tabWidget->currentWidget()->findChildren<QTableWidget*>())
    {
        currentTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        currentTableWidget->setColumnCount(8);

        currentTableWidget->setHorizontalHeaderLabels(QStringList() << "Talep Eden Kurum" <<"Adet" << "Teslim Tarihi" << "Sabit" <<"Periyot" <<"id" <<"criteriaEvaluationTypeId" << "criteriaId");

        currentTableWidget->setGeometry(10, 30, ui->tab_list_all->width() - 30, ui->tab_list_all->height() - 50);

        currentTableWidget->horizontalHeader()->resizeSection(0, 50);
        currentTableWidget->horizontalHeader()->resizeSection(1, 590);
        currentTableWidget->horizontalHeader()->resizeSection(2, 190);
        currentTableWidget->horizontalHeader()->resizeSection(3, 190);
        currentTableWidget->horizontalHeader()->resizeSection(4, 160);
        currentTableWidget->horizontalHeader()->resizeSection(5, 100);
        currentTableWidget->horizontalHeader()->resizeSection(6, 100);
        currentTableWidget->horizontalHeader()->resizeSection(7, 100);

        currentTableWidget->verticalHeader()->setDefaultSectionSize(40);

        currentTableWidget->setSortingEnabled(true);

        while (currentTableWidget->rowCount() > 0)
        {
            currentTableWidget->removeRow(0);
        }
    }

    comment("hello2");

    QString sutun1 = "Hello";
    QString sutun2 = "World.";
    QString upArea = "uparea";
    QString downArea = "uparea";
    QString constant = "uparea";
    QString periodic = "uparea";
    int id = 1;
    int sutun3 = 2;


    comment("hello3");

    static QTableWidgetItem *item;
    currentTableWidget->insertRow(currentTableWidget->rowCount());

    QCheckBox *checkBox = new QCheckBox();
    checkBox->setChecked(false);

    comment("hello4");


    item = new QTableWidgetItem(sutun1);
    item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled|Qt::ItemIsUserCheckable);
    item->setTextAlignment(Qt::AlignCenter | Qt::AlignVCenter);
    currentTableWidget->setItem(currentTableWidget->rowCount() - 1, 0, item);
    currentTableWidget->setCellWidget(currentTableWidget->rowCount()-1, 0, checkBox);

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





    currentTableWidget->show();

}

void miniWidget::comment(QString message)
{
    qDebug() << message;
}



void miniWidget::on_btn_close_clicked()
{
    this->close();
}

void miniWidget::tab_change(int index)
{
    comment("Hello first");
    if(index == 1){
        show_all_orders();
    }
}
