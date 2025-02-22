#ifndef PRODUCT_H
#define PRODUCT_H

#include<string>

class Product {
private:
    std::string ProductName;
    int ProductPrice;
    std::string ProductType;

public:   
    Product(const std::string& ProductName, int ProductPrice,const std::string& ProductType);
    std::string getProductName();
    void setProductPrice(const int newProductPrice);
    int getProductPrice();
    std::string getProductType();
};

#endif