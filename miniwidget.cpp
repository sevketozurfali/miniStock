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
    isblank = false;
    ui->lbl_result_add_city->setText("");

    city_name_list = new QStringList();


    ui->tabWidget->setTabText(0, "Sipariş");
    ui->tabWidget->setTabText(1, "İzleme");
    ui->tabWidget->setCurrentIndex(0);

    get_cities();

}

void miniWidget::on_btn_add_cityname_to_db_clicked()
{
    sqlLiteDatabase_initilization();

    if(add_new_city(ui->line_new_city_name->text())){
        close_database();
    }
    else{
        comment("Error :");
        qWarning() << db.lastError();

    }
}


void miniWidget::sqlLiteDatabase_initilization()
{
    const QString DRIVER("QSQLITE");

    if(QSqlDatabase::isDriverAvailable(DRIVER)){
        db = QSqlDatabase::addDatabase(DRIVER);
        db.setDatabaseName(QCoreApplication::applicationDirPath () + "/db_ministock.db");

        if(!db.open()){
            qWarning() << "Error! : " << db.lastError();
        }
        else
            comment("Database connection OK." + QCoreApplication::applicationDirPath ());
    }

}

void miniWidget::close_database(){
    db.close();
}



bool miniWidget::add_new_city(QString new_city_name){
    bool success = false;
    QSqlQuery query;
    query.prepare("INSERT INTO CITY_NAMES (NAME) VALUES (:new_city_name)");
    query.bindValue(":new_city_name", new_city_name);
    if(query.exec())
    {
        success = true;
        ui->lbl_result_add_city->setText(new_city_name + " başarı ile eklendi.");
    }
    else
    {
        qDebug() << "Ekleme hatası:"
                 << query.lastError();
        ui->lbl_result_add_city->setText(new_city_name + "eklenemedi." + query.lastError().text());
    }

    return success;
}

void miniWidget::get_cities(){

    ui->cmb_city->addItem("Şehir Seç...");

    city_name_list->clear();
    comment("city_name_list count : " + QString::number(city_name_list->size()));

    sqlLiteDatabase_initilization();
    QSqlQuery query;
    query.exec("SELECT * FROM CITY_NAMES");

    while (query.next()){
        QString name = query.value(0).toString();
        city_name_list->append(name);
        ui->cmb_city->addItem(name);
    }

    close_database();


}

void miniWidget::disconnections()
{
    disconnect(ui->tabWidget, &QTabWidget::currentChanged, this, &miniWidget::tab_change);


}

void miniWidget::connections()
{
    connect(ui->tabWidget, &QTabWidget::currentChanged, this, &miniWidget::tab_change);

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

void miniWidget::initilization_siparis()
{
//    get_definition_of_product_list();
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
    if(index == 0){
        initilization_siparis();
    }
}

bool miniWidget::check_all_blanks_in_order_section(){

    if(ui->line_customer_name->text() == ""){
        comment("Lütfen Müşteri Adı kutusunu boş bırakmayın...");
        return false;
    }
    else if(ui->cmb_city->currentIndex() == 0){
        comment("Lütfen Şehir bilgisini ekleyin.");
        return false;
    }
    else if(ui->cmb_definiton_of_product->currentIndex() == 0){
        comment("Lütfen Ürün Tanımı bilgisini ekleyin.");
        return false;
    }
    else if(ui->cmb_color->currentIndex() == 0){
        comment("Lütfen Renk bilgisini ekleyin.");
        return false;
    }
    else if(ui->spb_count_of_order->value() == 0){
        comment("Lütfen sipariş adetini ekleyin.");
        return false;
    }
    else if(!pick_order_date){
        comment("Lütfen sipariş tarihi bilgisini ekleyin.");
        return false;
    }
    else if(!pick_deadline){
        comment("Lütfen teslim tarihi bilgisini ekleyin.");
        return false;
    }
    else if(ui->line_salesman->text() == ""){
        comment("Lütfen satış yapan kişinin bilgisini ekleyin.");
        return false;
    }
    else{
        comment("All sections has been filled.");
        return true;
    }
}


void miniWidget::on_btn_add_clicked()
{
    if(check_all_blanks_in_order_section()){
        comment("add this info.");
    }
}

void miniWidget::on_btn_delete_clicked()
{
    ui->line_customer_name->setText("");
    ui->cmb_definiton_of_product->setCurrentIndex(0);
    ui->cmb_color->setCurrentIndex(0);
    ui->spb_count_of_order->setValue(0);
    order_date = "";
    deadline_date = "";
    ui->line_salesman->setText("");
}

void miniWidget::on_btn_pick_order_date_clicked()
{
    ui->date_layout->widget()->setVisible(true);
}

void miniWidget::on_btn_pick_deadline_clicked()
{
    ui->date_layout->widget()->setVisible(true);
}


