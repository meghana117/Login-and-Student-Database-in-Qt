#ifndef DB_CLASS_H
#define DB_CLASS_H

#include <QObject>
#include<StudentView.h>
#include<QtSql/QSqlDatabase>
#include<QtSql/QSqlError>
#include<QtSql/QSqlQuery>
#include<QDebug>
#include<Admin.h>
#include<QDir>

class Db_class : public QObject
{
    Q_OBJECT
public:
    explicit Db_class(QObject *parent = nullptr);
    bool checklog(Admin);
    bool add_student(StudentView);
    int getcount();
    void getdata(StudentView student[]);
    bool delete_stud(StudentView);
signals:

public slots:
};

#endif // DB_CLASS_H
