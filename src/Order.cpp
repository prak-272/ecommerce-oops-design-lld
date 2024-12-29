#include "../include/Order.hpp"
#include<iostream>
#include<memory>
#include<string>

int uniqueOrderId = 1;

Order::Order(std::vector<std::pair<std::shared_ptr<Product>,int> > OrderProducts,int OrderAmount,std::string OrderStatus,PaymentMethod MethodOfPayment) : OrderId(uniqueOrderId++), OrderProducts(OrderProducts), OrderAmount(OrderAmount), OrderStatus(OrderStatus), MethodOfPayment(MethodOfPayment) {}

bool Order::isOrderPossible(EcommerceManager& ecommerceManager) {
    Inventory* ProdcutInventory = ecommerceManager.getProductInventory();
    bool isProductAvailable = true;
    for(auto it = OrderProducts.begin(); it != OrderProducts.end(); it++) {
       int productAmount = ProdcutInventory->getProductAmount(it->first->getProductName());
       if(productAmount < it->second) {
        isProductAvailable = false;
        std::cout << "Product is not sufficiently available" << std::endl;
        std::cout << "Current Stock " << productAmount << std::endl; 
       }
    }
    return isProductAvailable;
}

void Order::paymentForOrder(EcommerceManager& ecommerceManager) {
    Inventory* ProdcutInventory = ecommerceManager.getProductInventory();
    for(auto it = OrderProducts.begin(); it != OrderProducts.end(); it++) {
       ProdcutInventory->updateProductStock(it->first->getProductName(),it->second);
    }
    OrderPayment = std::unique_ptr<Payment>(new Payment(MethodOfPayment,OrderAmount));
    OrderPayment->PaymentSuccessful();
    std::cout <<  "Order Successful";
    std::cout << std::endl;
    OrderStatus = "Delivered";
}

void Order::BrowseOrderProducts() {
    for(auto it : OrderProducts) {
        std::cout << "Product Name " << it.first->getProductName() << " Product Price " << it.first->getProductPrice() << " Product Type " << it.first->getProductType() << " Product Amount " << it.second << std::endl;
    }
}

int Order::getOrderId(){
    return OrderId;
}

std::vector<std::pair<std::shared_ptr<Product>,int > > Order::getOrderProducts() {
    return OrderProducts;
}

int Order::getOrderAmount() {
    return OrderAmount;
}

PaymentMethod Order::getMethodOfPayment(){
    return MethodOfPayment;
}