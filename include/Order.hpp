#ifndef ORDER_H
#define ORDER_H

#include "Product.hpp"
#include "Payment.hpp"
#include "EcommerceManager.hpp"
#include<vector>
#include<string>
#include<memory>

class Order { 

private:    
    int OrderId; 
    std::vector<std::pair<std::shared_ptr<Product>,int> > OrderProducts;
    int OrderAmount;
    std::string OrderStatus; 
    enum PaymentMethod MethodOfPayment;
    std::unique_ptr<Payment> OrderPayment;

public:
    Order(std::vector<std::pair<std::shared_ptr<Product>,int> > OrderProducts,int OrderAmount,std::string OrderStatus,PaymentMethod MethodOfPayment);
    void paymentForOrder(EcommerceManager& ecommerceManager);
    bool isOrderPossible(EcommerceManager& ecommerceManager);
    void BrowseOrderProducts();
    int getOrderId();
    std::vector<std::pair<std::shared_ptr<Product>,int > > getOrderProducts();
    int getOrderAmount();
    std::string getOrderStatus();
    PaymentMethod getMethodOfPayment();

}; 

#endif