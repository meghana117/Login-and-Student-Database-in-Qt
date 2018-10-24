#include "StudentV.h"

StudentV::StudentV(QWidget *parent) : QWidget(parent)
{
    this->setGeometry(450,250,550,500);
    table=new QTableView();
    model=new QStandardItemModel(1,4);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Name"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("USN"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Department"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("CGPA"));
    table->setModel(model);
    table->setColumnWidth(2,220);


    refresh = new QPushButton("Refresh");
    refresh->setFlat(true);

    hb2=new QHBoxLayout();
    add=new QPushButton("Add Student");
    del=new QPushButton("Delete Student");
    hb1=new QHBoxLayout();
    vb1=new QVBoxLayout();
    vb1->addWidget(table);
    hb2->addWidget(refresh);
    vb1->addLayout(hb2);
    hb1->addWidget(add);
    hb1->addWidget(del);
    vb1->addLayout(hb1);
    this->setLayout(vb1);
    setStyleSheet("background-color:#FFFCCC;");

    connect(add,SIGNAL(clicked(bool)),this,SLOT(add_stud()));
    connect(del,SIGNAL(clicked(bool)),this,SLOT(del_stud()));
    connect(refresh,SIGNAL(clicked(bool)),this,SLOT(refresh_page()));
}
void StudentV::func()
{
    StudentView students[db.getcount()];
    db.getdata(students);
    model->setRowCount(db.getcount());
    model->setColumnCount(4);
    for(int i=0;i<db.getcount();i++)
    {
        QStandardItem *item1=new QStandardItem(students[i].name);
        model->setItem(i,0,item1) ;
        QStandardItem *item2=new QStandardItem(students[i].usn);
        model->setItem(i,1,item2);
        QStandardItem *item3=new QStandardItem(students[i].dept);
        model->setItem(i,2,item3);
        QString s=QString::number(students[i].cgpa);
        QStandardItem *item4=new QStandardItem(s);
        model->setItem(i,3,item4);
    }

}
void StudentV::add_stud()
{

    stud.show();
}
void StudentV::del_stud()
{
    dele_stud.show();

}
void StudentV::refresh_page()
{
    this->func();
}
