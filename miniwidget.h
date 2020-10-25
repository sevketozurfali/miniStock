#ifndef MINIWIDGET_H
#define MINIWIDGET_H

#include <QWidget>
#include <QTableWidget>
#include <qdebug.h>
#include <QString>
#include <QStringList>
#include <QStandardItemModel>
#include <QTableWidgetItem>
#include <QTableWidget>
#include <QCheckBox>
#include <QHeaderView>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>

QT_BEGIN_NAMESPACE
namespace Ui { class miniWidget; }
QT_END_NAMESPACE

class miniWidget : public QWidget
{
    Q_OBJECT

public:
    miniWidget(QWidget *parent = nullptr);
    ~miniWidget();

    QWidget *createOrderWidget;

    QTableWidget *currentTableWidget;

    QCheckBox *checkBox;

    QString order_date;
    QString deadline_date;

    bool pick_order_date;
    bool pick_deadline;
    bool isblank;

    QSqlDatabase db;
//    QSqlQuery query;

    QStringList *city_name_list;


private slots:

    void connections();
    void disconnections();

    void initilization();

    bool add_new_city(QString new_city_name);

    void sqlLiteDatabase_initilization();

    void close_database();

    void get_cities();

//    ----------------------------------------------------------------------------

    void on_btn_close_clicked();

    void tab_change(int index);

    void show_all_orders();

    void comment(QString message);

    void initilization_siparis();

    void on_btn_add_clicked();

    void on_btn_delete_clicked();

    void on_btn_pick_order_date_clicked();

    void on_btn_pick_deadline_clicked();

    bool check_all_blanks_in_order_section();





    void on_btn_add_cityname_to_db_clicked();

signals:


private:
    Ui::miniWidget *ui;


};
#endif // MINIWIDGET_H
