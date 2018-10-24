#ifndef STUDENTVIEW_H
#define STUDENTVIEW_H

#include<QPushButton>
#include<QDate>
#include<QString>
class StudentView
{
public:
    StudentView();

public:
    QString name,usn,password,email,dept;
    QDate dob;
    double cgpa;
    int backlog;
    long long contact;

};

#endif // STUDENTVIEW_H
