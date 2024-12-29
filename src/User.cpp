#include "../include/User.hpp"
#include<string>

User::User(const std::string& UserName,const std::string& UserPhoneNo,const std::string& UserAddress,bool isLoggedIn) : UserName(UserName), UserPhoneNo(UserPhoneNo), UserAddress(UserAddress), isLoggedIn(isLoggedIn) {}

void User::Login() {
   isLoggedIn = true;
}

void User::Logout() {
   isLoggedIn = false;
}

User::~User() {

}