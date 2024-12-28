#ifndef ADMIN_H
#define ADMIN_H

#include "Product.hpp"
#include "User.hpp"
#include "EcommerceManager.hpp"
#include <memory>
#include<string>

class Admin: public User {

private: 
   int AdminId;

public: 
    Admin(const std::string& UserName,const std::string& UserPhoneNo,const std::string& UserAddress,bool isLoeggedIn);  
    bool isAdminLoggedIn();
    void addToInventory(EcommerceManager& ecommerceManager,std::string ProductName,int ProdcutPrice, std::string  ProductType,int ProductAmount);
    void removeFromInventory(EcommerceManager& ecommerceManager,std::string ProductName );
    void updateInInventory(EcommerceManager& ecommerceManager,std::string ProductName,int updateInStock);
    void updateProductPrice(EcommerceManager& ecommerceManager,std::string ProductName,int newProductPrice);
    int getAdminId();
};

#endif