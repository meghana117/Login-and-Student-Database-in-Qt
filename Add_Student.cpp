#include "Add_Student.h"


Add_Student::Add_Student(QWidget *parent) : QWidget(parent)
{
    this->setGeometry(450,250,500,500);
    m_calButton = new QPushButton("Select");
    m_calButton->setFlat(true);

    add=new QPushButton("Add");
    cancel=new QPushButton("Cancel");
    name=new QLabel("Name");
    usn=new QLabel("USN");
    pass=new QLabel("DOB");
    email=new QLabel("Email");
    dept=new QLabel("Department");
    contact=new QLabel("Contact no.");
    cgpa=new QLabel("CGPA");
    backlog=new QLabel("No. of backlogs");
    error=new QLabel();
    name_edit=new QLineEdit();
    QRegExp valid_name("[a-zA-Z ]+");
    QRegExpValidator *validate_name=new QRegExpValidator(valid_name,this);

    name_edit->setValidator(validate_name);

    QRegExp expusn("^[1]{1}[Dd]{1}[Aa]{1}[0-9]{2}[A-Za-z]{2}[0-9]{3}$/i");
    QRegExpValidator *validate_usn=new QRegExpValidator(expusn,this);
    usn_edit=new QLineEdit();
    usn_edit->setValidator(validate_usn);


    m_cal = new QCalendarWidget;
    m_cal->setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);

    QRegExp rx("^[a-zA-Z0-9_\.\-]+@[a-zA-Z0-9_\.\-]+\.[a-zA-Z]{2,5}$");
    QRegExpValidator *validate_email=new QRegExpValidator(rx,this);
    email_edit=new QLineEdit();
    email_edit->setValidator(validate_email);
    dept_edit=new QComboBox();
    QStringList list={"Computer Science and Engineering","Electronics and Communications Engineering","Mechanical Engineering","Civil Engineering","Electrical Engineering","Medical Electronics Engineering","Information Science and Engineering","Telecommunication and Engineering"};
    dept_edit->addItems(list);
    dept_edit->clear();
    QRegExp expcontact("[1-9]{1}[0-9]{9}");
    QRegExpValidator *validate_contact=new QRegExpValidator(expcontact,this);
    contact_edit=new QLineEdit();
    contact_edit->setValidator(validate_contact);
    cgpa_edit=new QDoubleSpinBox();
    cgpa_edit->setMaximum(10.0);
    backlog_edit=new QSpinBox();
    backlog_edit->setMaximum(10);
    add=new QPushButton("Add");
    cancel=new QPushButton("Cancel");
    vb1=new QVBoxLayout();
    vb2=new QVBoxLayout();
    vb3=new QVBoxLayout();
    vb4=new QVBoxLayout();
    vb5=new QVBoxLayout();
    vb6=new QVBoxLayout();
    vb7=new QVBoxLayout();
    vb8=new QVBoxLayout();
    hb1=new QHBoxLayout();
    hb2=new QHBoxLayout();
    hb3=new QHBoxLayout();
    hb4=new QHBoxLayout();
    hb5=new QHBoxLayout();
    hb6=new QHBoxLayout();
    hb7=new QHBoxLayout();
    hb8=new QHBoxLayout();
    hb9=new QHBoxLayout();
    hb10=new QHBoxLayout();
    hb1->addWidget(name);
    hb1->addWidget(name_edit);
    hb2->addWidget(pass);
    hb2->addWidget(m_calButton);
    vb1->addLayout(hb1);
    vb1->addLayout(hb2);
    hb3->addWidget(email);
    hb3->addWidget(email_edit);
    vb1->addLayout(hb3);
    hb4->addWidget(contact);
    hb4->addWidget(contact_edit);
    vb1->addLayout(hb4);
    hb5->addWidget(dept);
    hb5->addWidget(dept_edit);
    vb1->addLayout(hb5);
    hb6->addWidget(usn);
    hb6->addWidget(usn_edit);
    vb1->addLayout(hb6);
    hb7->addWidget(cgpa);
    hb7->addWidget(cgpa_edit);
    vb1->addLayout(hb7);
    hb8->addWidget(backlog);
    hb8->addWidget(backlog_edit);
    vb1->addLayout(hb8);
    hb9->addWidget(error);
    vb1->addLayout(hb9);
    hb10->addWidget(add);
    hb10->addWidget(cancel);
    vb1->addLayout(hb10);
    this->setLayout(vb1);
    setStyleSheet("background-color:#FFFCCC;");

    connect(add,SIGNAL(clicked(bool)),this,SLOT(add_stud()));
    connect(m_calButton,SIGNAL(clicked()),m_cal,SLOT(show()),Qt::UniqueConnection);
    connect(m_cal,SIGNAL(clicked(QDate)),this,SLOT(onDateSelected(QDate)),Qt::UniqueConnection);
    connect(cancel,SIGNAL(clicked(bool)),this,SLOT(closed()));
}
void Add_Student::add_stud()
{
    StudentView student;
    QDate today;
    today=today.currentDate();
    student.name=name_edit->text();
    student.usn=usn_edit->text();
    student.backlog=backlog_edit->value();
    student.cgpa=cgpa_edit->value();
    student.contact=contact_edit->text().toLongLong();
    student.dept=dept_edit->currentText();
    student.email=email_edit->text();
    student.password=m_date.toString("dd/MM/yyyy");
    student.dob=m_date;

    if(student.name.isEmpty()||student.usn.isEmpty()||student.contact==NULL || student.email.isEmpty()|| student.usn.isEmpty()|| student.dept.isEmpty() || student.dob==today)
    {
        QMessageBox msgBox;
        msgBox.setText("Please enter valid data for all the fields");
        msgBox.exec();
    }
    else
    {

        Db_class db;
        if(db.add_student(student))
        {
            QMessageBox msgBox;
            msgBox.setText("Student added Successfully!");
            msgBox.exec();
            name_edit->clear();
            usn_edit->clear();
            dept_edit->clear();
            contact_edit->clear();
            email_edit->clear();
            cgpa_edit->clear();
            backlog_edit->clear();
        }
    }
}
void Add_Student::closed()
{
    this->close();
}

void Add_Student::onDateSelected(QDate date)
{
    m_cal->close();
    m_date = date;
    m_calButton->setText(date.toString("dd MMM yyyy,ddd"));
}
