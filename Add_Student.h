#ifndef ADD_STUDENT_H
#define ADD_STUDENT_H

#include <QWidget>
#include<QCalendarWidget>
#include<QRegExp>
#include<QValidator>
#include<QComboBox>
#include<QLineEdit>
#include<QLabel>
#include<QString>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QDateEdit>
#include<QPushButton>
#include<QDoubleSpinBox>
#include<QSpinBox>
#include<StudentView.h>
#include<QMessageBox>
#include<Db_class.h>
//#include<StudentV.h>

class Add_Student : public QWidget
{
    Q_OBJECT
public:
    explicit Add_Student(QWidget *parent = nullptr);


private:
    QLabel *name,*usn,*pass,*email,*dept,*contact,*backlog,*cgpa,*error;
    QDoubleSpinBox *cgpa_edit;
    QComboBox *dept_edit;
    QCalendarWidget *m_cal;
        QDate m_date;
    QDateEdit *DOB;
    QSpinBox *backlog_edit;
    QPushButton *add,*cancel,*m_calButton;
    QLineEdit *name_edit,*usn_edit,*pass_edit,*email_edit,*contact_edit;
    QVBoxLayout *vb1,*vb2,*vb3,*vb4,*vb5,*vb6,*vb7,*vb8;
    QHBoxLayout *hb1,*hb2,*hb3,*hb4,*hb5,*hb6,*hb7,*hb8,*hb9,*hb10;


signals:

public slots:
        void add_stud();
        void closed();
        void onDateSelected(QDate date);
};

#endif // ADD_STUDENT_H
