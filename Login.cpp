#include "Login.h"

Login::Login()
{

}

bool Login::check_log(Admin ad)
{
    bool present;
    Db_class db;
    present=db.checklog(ad);
    if(present)
    {
        return true;
    }
    else {
        return false;
    }
}
