#include "../include/Customer.hpp"
#include<iostream>

int uniqueId = 1;

Customer::Customer(const std::string& UserName,const std::string& UserPhoneNo, const std::string& UserAddress,bool isLoggedIn) : User(UserName, UserPhoneNo, UserAddress, isLoggedIn), CustomerId(uniqueId++), customerCart(std::unique_ptr<Cart>(new Cart)) {} 

bool Customer::isCustomerLoggedIn() {
    if(!isLoggedIn) {
        std::cout << "Customer is not logged in. Please Login" << std::endl;
        return false;
    }
    return true;
}

void Customer::addToCart(EcommerceManager& ecommerceManager,std::string ProductName,int ProductAmount){
    if(!isCustomerLoggedIn())return;
    customerCart->AddToCartProducts(ecommerceManager, ProductName, ProductAmount);
}

void Customer::removeFromCart(EcommerceManager& ecommerceManager,std::string ProductName) {
   if(!isCustomerLoggedIn())return;
   customerCart->RemoveFromCartProducts(ecommerceManager, ProductName);
}

void Customer::OrderCartItems(PaymentMethod methodForPayment, EcommerceManager& ecommerceManager){
    std::unique_ptr<Order> customerOrder = std::unique_ptr<Order>(new Order(customerCart->getCartProducts(),customerCart->getTotalPrice(),"Pending",methodForPayment));
    if(customerOrder->isOrderPossible(ecommerceManager)) { 
       customerOrder->paymentForOrder(ecommerceManager);                                    
    }
    customerCart->setCartProducts(std::vector<std::pair<std::shared_ptr<Product>, int>  >());
    customerCart->setTotalPrice(0);
    previousOrders.push_back(std::move(customerOrder));
}

void Customer::browseCart(){
    customerCart->browseCart();
}

void Customer::browseInventory(EcommerceManager& ecommerceManager){
    Inventory* ProductInvenory = ecommerceManager.getProductInventory();
    ProductInvenory->browseInventory();
}

void Customer::browsePastOrders() {
   for(auto& it: previousOrders) {
        std::cout << "Order Id" << it->getOrderId() << std::endl;
        std::cout << "Order Prodcuts " << std::endl;
        browsePastOrders();
        std::cout << "Order Amount " << it->getOrderAmount() << std::endl;
        // std::cout << "Method Of Payment " << PaymentMethod::(it->getMethodOfPayment());
        std::cout << std::endl;
   }
}

int Customer::getCustomerId(){
    return CustomerId;
}