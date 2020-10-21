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

//    QTableWidgetItem *item;

private slots:

    void connections();
    void disconnections();

    void initilization();

    void sqlLiteDatabase_initilization();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_btn_close_clicked();

    void tab_change(int index);

    void show_all_orders();

    void comment(QString message);

signals:


private:
    Ui::miniWidget *ui;


};
#endif // MINIWIDGET_H
