#include "../include/Admin.hpp"
#include<string>
#include<iostream>
int uniqueId  = 1;

Admin::Admin(const std::string& UserName,const std::string& UserPhoneNo,const std::string& UserAddress,bool isLoggedIn) : User(UserName,UserPhoneNo,UserAddress,isLoggedIn), AdminId(uniqueId++) {}

bool Admin::isAdminLoggedIn() {
    if(!isLoggedIn){
      std::cout << "Admin is not logged  in. Please  Login";
      return false;
    } 
    return true;
}

void Admin::addToInventory(EcommerceManager& ecommerceManager,std::string ProductName,int ProductPrice, std::string  ProductType,int ProductAmount) {
    if(!isAdminLoggedIn())return;
    ecommerceManager.getProductInventory()->addProduct(ProductName,ProductPrice,ProductType, ProductAmount);
}

void Admin::removeFromInventory(EcommerceManager& ecommerceManager,std::string ProductName ) {
    if(!isAdminLoggedIn())return;
    ecommerceManager.getProductInventory()->removeProduct(ProductName);
}

void Admin::updateInInventory(EcommerceManager& ecommerceManager,std::string ProductName,int updateInStock){
    if(!isAdminLoggedIn())return;
    ecommerceManager.getProductInventory()->updateProductStock(ProductName,updateInStock);
}

void Admin::updateProductPrice(EcommerceManager &ecommerceManager, std::string ProductName, int newProductPrice){
    if(!isAdminLoggedIn())return;
    ecommerceManager.getProductInventory()->updateProductPriceInInventory(ProductName, newProductPrice);
}

int Admin::getAdminId() {
    return AdminId;
}