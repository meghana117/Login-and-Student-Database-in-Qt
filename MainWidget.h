#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <Admin.h>
#include <Login.h>
#include<QMessageBox>
#include<QDebug>
#include<StudentV.h>

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = 0);
    ~MainWidget();

private:
    QVBoxLayout *vb1,*vb2;
    QHBoxLayout *hb1,*hb2,*hb3,*hb4;
    QPushButton *login;
    QLineEdit *uname,*upass;
    QLabel *name,*pass,*head,*showlabel;
    StudentV student;

public slots:
    void check();
};

#endif // MAINWIDGET_H
