/**
  @author Prakhar Kumar
  @brief An ecommerce cli application 
 */

#include "../include/Admin.hpp"
#include "../include/Cart.hpp"
#include "../include/EcommerceManager.hpp"
#include "../include/Customer.hpp"
#include "../include/Inventory.hpp"
#include<iostream>
#include <memory>
#include "../include/Order.hpp"
#include "../include/Product.hpp"
#include "../include/Payment.hpp"
#include "../include/User.hpp"

int main()
{ 
    EcommerceManager* ecommerceManager = new EcommerceManager();
    Admin* AdminAccount  = dynamic_cast<Admin*>(ecommerceManager->registerAccount("Admin", "Prakhar1",  "9631291811", "Kolkata"));
    AdminAccount->Admin::addToInventory(*ecommerceManager,"Gwen1 Watch",100,"Toy",4);
    AdminAccount->Admin::addToInventory(*ecommerceManager,"Gwen2 Watch",120,"Toy",2);
    AdminAccount->Admin::addToInventory(*ecommerceManager,"Gwen3 Watch",150,"Toy",4);
    AdminAccount->Admin::addToInventory(*ecommerceManager,"Gwen4 Watch",190,"Toy",8);
    Customer* CustomerAccount = dynamic_cast<Customer*>(ecommerceManager->registerAccount("Customer", "Prakhar2",  "9631291811", "Greater Noida"));
    CustomerAccount->Customer::browseInventory(*ecommerceManager);
    CustomerAccount->Customer::addToCart(*ecommerceManager,"Gwen1 Watch", 2);
    CustomerAccount->Customer::addToCart(*ecommerceManager,"Gwen4 Watch", 4);
    CustomerAccount->Customer::UpdateCartProducts(*ecommerceManager,"Gwen1 Watch",4);
    CustomerAccount->Customer::addToCart(*ecommerceManager,"Gwen2 Watch", 4);
    CustomerAccount->Customer::browseCart();
    AdminAccount->Admin::removeFromInventory(*ecommerceManager, "Gwen3 Watch");
    AdminAccount->Admin::updateInInventory(*ecommerceManager, "Gwen2 Watch", 4);
    CustomerAccount->Customer::addToCart(*ecommerceManager, "Gwen2 Watch", 4);
    Customer* CustomerAccount1 = dynamic_cast<Customer*>(ecommerceManager->registerAccount("Customer", "Prakhar2",  "9631291811", "Greater Noida"));
    CustomerAccount1->Customer::browseInventory(*ecommerceManager);
    CustomerAccount1->Customer::addToCart(*ecommerceManager,"Gwen1 Watch", 2);
    CustomerAccount->Customer::addToCart(*ecommerceManager,"Gwen3 Watch", 8);
    CustomerAccount->Customer::addToCart(*ecommerceManager,"Gwen4 Watch", 8);
    CustomerAccount->Customer::browseCart();
    CustomerAccount->Customer::OrderCartItems(PaymentMethod::CreditCard, *ecommerceManager);
    CustomerAccount->Customer::browsePastOrders();
    CustomerAccount->Customer::OrderCartItems(PaymentMethod::DebitCard, *ecommerceManager);
    AdminAccount->Admin::updateInInventory(*ecommerceManager, "Gwen1 Watch", 12);
    CustomerAccount1->Customer::OrderCartItems(PaymentMethod::DebitCard, *ecommerceManager);
    

}