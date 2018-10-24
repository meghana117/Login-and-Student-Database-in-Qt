#include "Delete_Student.h"

Delete_Student::Delete_Student(QWidget *parent) : QWidget(parent)
{
    this->setGeometry(450,250,300,150);
    label=new QLabel("USN to delete");
    head=new QLabel("Delete Student");
    del=new QPushButton("Delete");
    cancel=new QPushButton("Cancel");
    hb1=new QHBoxLayout();
    hb2=new QHBoxLayout();
    vb1=new QVBoxLayout();
    QRegExp expusn("^[1]{1}[dD]{1}[aA]{1}[0-9]{2}[a-zA-Z]{2}[0-9]{3}$/i");
    QRegExpValidator *validate_usn=new QRegExpValidator(expusn,this);
    usn=new QLineEdit();
    usn->setValidator(validate_usn);
    vb1->addWidget(head);
    hb1->addWidget(label);
    hb1->addWidget(usn);
    vb1->addLayout(hb1);
    hb2->addWidget(del);
    hb2->addWidget(cancel);
    vb1->addLayout(hb2);
    this->setLayout(vb1);
    setStyleSheet("background-color:#FFFCCC;");
    connect(del,SIGNAL(clicked(bool)),this,SLOT(del_stud()));
    connect(cancel,SIGNAL(clicked(bool)),this,SLOT(back()));

}

void Delete_Student::del_stud()
{
    Db_class db;
    StudentView student;
    student.usn=usn->text();
    if(db.delete_stud(student))
    {
        QMessageBox msgBox;
        msgBox.setText("Student deleted Successfully!");
        msgBox.exec();
        usn->clear();
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("Please enter valid usn or usn doesn't exist!");
        msgBox.exec();
    }

}
void Delete_Student::back()
{
    this->close();
}
