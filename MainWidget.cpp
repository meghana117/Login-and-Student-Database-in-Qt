#include "MainWidget.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    this->setGeometry(450,250,200,200);
    uname=new QLineEdit();
    upass=new QLineEdit();
    login=new QPushButton("Login");
    name=new QLabel("Username");
    pass=new QLabel("Password");
    showlabel=new QLabel();
    upass->setEchoMode(QLineEdit::Password);
    vb1=new QVBoxLayout();
    vb2=new QVBoxLayout();
    hb1=new QHBoxLayout();
    hb1->setAlignment(Qt::AlignCenter);
    head=new QLabel("Login Page");
    hb2=new QHBoxLayout();
    hb3=new QHBoxLayout();
    hb4=new QHBoxLayout();
    hb1->addWidget(head);
    hb2->addWidget(name);
    hb2->addWidget(uname);
    hb3->addWidget(pass);
    hb3->addWidget(upass);
    hb4->addWidget(login);
    hb4->addWidget(showlabel);
    vb1->addLayout(hb1);
    vb1->addLayout(hb2);
    vb1->addLayout(hb3);
    vb1->addLayout(hb4);
    this->setLayout(vb1);
    setStyleSheet("background-color:#FFFCCC;");
    connect(login,SIGNAL(clicked(bool)),this,SLOT(check()));

}

void MainWidget::check()
{
    Admin ad;
    ad.uid=uname->text();
    ad.pass=upass->text();
    Login l;
    bool yes;
    yes=l.check_log(ad);
    if(yes)
    {
        showlabel->setText("Successful login");
        student.func();
        student.show();
        this->close();
    }
    else {
        showlabel->setText("Login failed");
        showlabel->setStyleSheet("color:red");
    }
}
MainWidget::~MainWidget()
{

}
