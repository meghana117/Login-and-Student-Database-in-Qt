#ifndef DELETE_STUDENT_H
#define DELETE_STUDENT_H

#include <QWidget>
#include<QLineEdit>
#include<QRegExpValidator>
#include<QValidator>
#include<QRegExp>
#include<QPushButton>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QLabel>
#include<Db_class.h>
#include<QMessageBox>


class Delete_Student : public QWidget
{
    Q_OBJECT
public:
    explicit Delete_Student(QWidget *parent = nullptr);


private:
    QLabel *head,*label;
    QPushButton *del,*cancel;
    QLineEdit *usn;
    QHBoxLayout *hb1,*hb2;
    QVBoxLayout *vb1;



signals:

public slots:
    void del_stud();
    void back();
};

#endif // DELETE_STUDENT_H
