#ifndef CART_H
#define CART_H

#include "EcommerceManager.hpp"
#include "Product.hpp"
#include<vector>
#include<memory>

class Cart {
private:
    std::vector<std::pair<std::shared_ptr<Product>, int> > cartProducts;
    int totalPrice; 

public:
    Cart();
    void AddToCartProducts(EcommerceManager& ecommerceManager,std::string ProductName,int ProductAmount);
    void RemoveFromCartProducts(EcommerceManager& ecommerceManager,std::string ProductName);
    void UpdateAmountOfProduct(EcommerceManager& ecommerceManager,std::string ProductName,int newAmount);
    void browseCart();
    std::vector<std::pair<std::shared_ptr<Product>, int> > getCartProducts();
    int getTotalPrice();
    int getCartProductAmount(std::string ProductName);
    void setCartProducts(std::vector<std::pair<std::shared_ptr<Product>, int> > newCartProducts);
    void setTotalPrice(int newTotalPrice);
    void UpdateCartPrice(int ProductPrice,int DifferenceInProductAmount);

};

#endif