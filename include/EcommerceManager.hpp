#ifndef ECOMMERCEMANAGER_HPP
#define ECOMMERCEMANAGER_HPP

#include "Inventory.hpp"
#include "User.hpp"
#include<vector>
#include<memory>

class EcommerceManager {

private:
    std::vector<std::unique_ptr<User> > Users;
    std::unique_ptr<Inventory> ProductInventory;

public:
   EcommerceManager();
   void registerAccount(const std::string& accountType,const std::string& UserName, const std::string& UserPhoneNo,const std::string& UserAddress);
   void removeAdminAccount(int adminId);
   void removeCustomerAccount(int customerId);
   Inventory* getProductInventory();
};

#endif

