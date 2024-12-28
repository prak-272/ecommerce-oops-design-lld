#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "EcommerceManager.hpp"
#include "User.hpp"
#include "Cart.hpp"
#include "Order.hpp"
#include "Payment.hpp"
#include<vector>
#include<string>


class Customer : public User {

private:
   int CustomerId;
   std::unique_ptr<Cart> customerCart;
   std::vector<std::unique_ptr<Order> > previousOrders;

public:
    Customer(const std::string& UserName,const std::string& UserPhoneNo, const std::string& UserAddress,bool isLoggedIn);
    void addToCart(EcommerceManager& ecommerceManager,std::string ProductName,int ProductAmount);
    void removeFromCart(EcommerceManager& ecommerceManager,std::string ProductName);
    void OrderCartItems(PaymentMethod methodForPayment,EcommerceManager& ecommerceManager);
    void browseCart();
    void browseInventory(EcommerceManager& ecommerceManager);
    void browsePastOrders();
    bool isCustomerLoggedIn();
    int getCustomerId();
};

#endif