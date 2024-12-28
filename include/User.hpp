#ifndef USER_H
#define USER_H

#include<string>

class User {
protected:    
    std::string UserName;
    std::string UserPhoneNo;
    std::string UserAddress;
    bool isLoggedIn;

public:
    User(const std::string& UserName,const std::string& UserPhoneNo,const std::string& UserAddress,bool isLoggedIn);
    void Login();
    void Logout();
    virtual ~User();
};

#endif