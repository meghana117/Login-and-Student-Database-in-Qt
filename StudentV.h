#ifndef STUDENTV_H
#define STUDENTV_H

#include <QWidget>
#include<QPushButton>
#include<QHBoxLayout>
#include"Db_class.h"
#include<QTableView>
#include<QStandardItem>
#include<QStandardItemModel>
#include<Add_Student.h>
#include<Delete_Student.h>


class StudentV : public QWidget
{
    Q_OBJECT
public:
    explicit StudentV(QWidget *parent = nullptr);
    void func();

private:
    QPushButton *add,*del,*refresh,*m_calbutton;
    QHBoxLayout *hb1,*hb2;
    QVBoxLayout *vb1;
    QTableView *table;
    QStandardItemModel *model;
    Db_class db;
    Add_Student stud;
    Delete_Student dele_stud;


signals:

public slots:
    void add_stud();
    void del_stud();
    void refresh_page();
};

#endif // STUDENTV_H
