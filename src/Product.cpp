#include "../include/Product.hpp"

Product::Product(const std::string& ProductName, const int ProductPrice,const std::string& ProductType) : ProductName(ProductName), ProductPrice(ProductPrice), ProductType(ProductType) {}

std::string Product::getProductName() {
    return ProductName;
}

void Product::setProductPrice(const int newProductPrice) {
    ProductPrice = newProductPrice;
}

int Product::getProductPrice(){
    return ProductPrice;
}

std::string Product::getProductType() {
    return ProductType;
}