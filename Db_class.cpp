#include "Db_class.h"

Db_class::Db_class(QObject *parent) : QObject(parent)
{

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("Sample.db");

    if(db.open()){
        qDebug() << "DB File Opened" << endl;

        //QString s = QDir::currentPath();
        //QDir dir(s);
        //QStringList lst = dir.entryList();
        //qDebug() << lst << endl;

        QSqlQuery query;
        query.prepare("create table if not exists Admin(name varchar(30) primary key,password varchar(30))");
        query.exec();
        query.prepare("insert into Admin values('admin','admin123')");
        query.exec();
        query.prepare("create table if not exists Student(id INTEGER PRIMARY KEY,name varchar(30),USN varchar(10) UNIQUE, email varchar(30),dept varchar(30),contact varchar(10),cgpa float,backlog INTEGER,password varchar(30), DOB varchar(10))");
        query.exec();
        qDebug() << "Tables created " << db.lastError();
    }
    else{
        qDebug() << "DB File didnt open" << endl;
    }

}
bool Db_class::checklog(Admin a)
{
    QSqlQuery qry;
    QString n,p;
    qry.prepare("SELECT * from Admin");
    if(qry.exec()){
    while(qry.next())
    {
        n=qry.value("name").toString();
        qDebug()<<n<<""<<p<<endl;
        p=qry.value("password").toString();
        if(n==a.uid && p==a.pass)
        {
            return true;
        }
    }
    }
    qDebug()<<n<<"  "<<p<<endl;
    return false;
}
bool Db_class::add_student(StudentView student)
{
    QSqlQuery query;
//    static int id;
    qDebug()<<query.lastError();
    query.prepare("insert into Student(name,USN,email,dept,contact,cgpa,backlog,password,DOB) values (:Name,:Usn,:Email,:Dept,:Contact,:Cgpa,:Backlog,:Password,:Dob);");
//    query.bindValue(":id",id++);
    query.bindValue(":Name",student.name);
    query.bindValue(":Usn",student.usn);
    query.bindValue(":Email",student.email);
    query.bindValue(":Dept",student.dept);
    query.bindValue(":Contact",student.contact);
    query.bindValue(":Cgpa",student.cgpa);
    query.bindValue(":Backlog",student.backlog);
    query.bindValue(":Password",student.password);
    query.bindValue(":Dob",student.dob.toString("dd/MM/yyyy"));
    if(query.exec())
    {
        return true;
    }
    qDebug()<<query.lastError()<< "Error ";
}
int Db_class::getcount()
{
    QSqlQuery qry;
    qry.prepare("Select count(rowid) from Student;");
    qry.exec();
    while (qry.next()) {
        return (qry.value(0).toInt());
    }
}
void Db_class::getdata(StudentView student[])
{
    QSqlQuery query;
    int i=0;
    query.prepare("Select * from Student;");
    query.exec();
    while(query.next())
    {
        student[i].name=query.value("name").toString();
        student[i].usn=query.value("USN").toString();
        student[i].dept=query.value("dept").toString();
        student[i].cgpa=query.value("cgpa").toDouble();
//        qDebug()<<student[i].cgpa;
        i++;
    }
    qDebug()<<query.lastError();
}
bool Db_class::delete_stud(StudentView stud)
{
    QSqlQuery qry;
    qry.prepare("Delete from Student where USN= :usn;");
    qry.bindValue(":usn",stud.usn);
    qry.exec();
    if(qry.numRowsAffected()==0)
    {
        return false;
    }
    else
        return true;
}
