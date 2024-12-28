#include "../include/EcommerceManager.hpp"
#include "../include/Inventory.hpp"
#include "../include/User.hpp"
#include "../include/Admin.hpp"
#include "../include/Customer.hpp"
#include<memory>
#include<iostream>


EcommerceManager::EcommerceManager() : ProductInventory(std::unique_ptr<Inventory>(new Inventory())) {}

void EcommerceManager::registerAccount(const std::string& accountType,const std::string& UserName, const std::string& UserPhoneNo,const std::string& UserAddress) {
    if(accountType == "admin") {
       std::unique_ptr<User> newUser = std::unique_ptr<User>(new Admin(UserName,UserPhoneNo,UserAddress,true));
       Users.push_back(std::move(newUser));
       std::cout << "Admin account successfully registered" << std::endl;
       return;
    }
    else if(accountType == "customer") {
        std::unique_ptr<User> newUser = std::unique_ptr<User>(new Customer(UserName,UserAddress,UserPhoneNo,true));
        Users.push_back(std::move(newUser));
        std::cout << "Customer Account is successfully registered" << std::endl;
        return;
    }
    std::cout << "Account could not be registered. Please check entry and re submit" << std::endl;

}

Inventory* EcommerceManager::getProductInventory() {
    return ProductInventory.get();
}

void EcommerceManager::removeAdminAccount(int AdminId) {
    for(auto it = Users.begin(); it != Users.end(); it++) {
        Admin* currentAdmin = dynamic_cast<Admin*>(it->get());
        if(currentAdmin){
            if(currentAdmin->getAdminId() == AdminId){
                Users.erase(it);
                std::cout << "Admin Account is successfuly removed" << std::endl;
                return;
            }
        }
    }

    std::cout << "No Admin Account exists with id " << AdminId << std::endl; 
}

void EcommerceManager::removeCustomerAccount(int customerId) {
    for(auto it = Users.begin(); it != Users.end(); it++) {
        Customer* currentCustomer = dynamic_cast<Customer*>(it->get());
        if(currentCustomer){
            if(currentCustomer->getCustomerId() == customerId) {
                Users.erase(it);
                std::cout << "Customer Account is successfully removed" << std::endl;
                return;
            }
        }
    }

    std::cout << "No Customer Account exists with id " << customerId << std::endl;
}