#ifndef LOGIN_H
#define LOGIN_H

#include <QObject>
#include<Admin.h>
#include<Db_class.h>

class Login
{
public:
    Login();
    bool check_log(Admin);
};

#endif // LOGIN_H
