#include "../include/Cart.hpp"
#include "../include/Product.hpp"
#include<iostream>

Cart::Cart() {}

void Cart::AddToCartProducts(EcommerceManager& ecommerceManager,std::string ProductName,int ProductAmount) {
    Inventory* ProductInventory = ecommerceManager.getProductInventory();
    int InventoryProductAmount = ProductInventory->getProductAmount(ProductName);
    if(InventoryProductAmount <= ProductAmount){
        cartProducts.push_back(std::make_pair(ProductInventory->getProduct(ProductName), ProductAmount));
        std::cout << "Product" << ProductName << "is added to cart" << std::endl;
        UpdateCartPrice(ProductInventory->getProduct(ProductName)->getProductPrice(), ProductAmount);
        return;
    }
    std::cout << "Product" <<  ProductName << "is not sufficiently available in Inventory" << std::endl;
    std::cout << "Current Stock " << InventoryProductAmount << std::endl;
}

void Cart::RemoveFromCartProducts(EcommerceManager& ecommerceManager,std::string ProductName) {
    Inventory* ProductInventory = ecommerceManager.getProductInventory();
    for(auto it = cartProducts.begin(); it != cartProducts.end(); it++) {
        if(it->first->getProductName() == ProductName) {
            cartProducts.erase(it);
            std::cout << "Product" << ProductName << "is removed from cart" << std::endl;
            UpdateCartPrice(ProductInventory->getProduct(ProductName)->getProductPrice(), getCartProductAmount(ProductName));
            return;
        }
    }
    std::cout << "Product" << ProductName << "is not present in cart" << std::endl;
}

void Cart::UpdateAmountOfProduct(EcommerceManager &ecommerceManager, std::string ProductName, int newAmount) {
    Inventory* ProductInventory = ecommerceManager.getProductInventory();
    for(auto it = cartProducts.begin(); it != cartProducts.end(); it++) {
        if(it->first->getProductName() == ProductName) {
            it->second = newAmount;
            std::cout << "Product" << ProductName << "amount is updated in cart" << std::endl;
            UpdateCartPrice(ProductInventory->getProduct(ProductName)->getProductPrice(), newAmount - getCartProductAmount(ProductName));
            return;
        }
    }
    std::cout << "Product" << ProductName << "is not present in cart" << std::endl;
}

void Cart::browseCart() {
    for(auto it: cartProducts) {
       std::cout << "Product Name " <<  it.first->getProductName() << " Product Price " << it.first->getProductPrice() <<  " Product Type " << it.first->getProductType() << " Product Amount " << it.second << std::endl;
    }
}

std::vector<std::pair<std::shared_ptr<Product>,int > > Cart::getCartProducts() {
    return cartProducts;
}

int Cart::getTotalPrice() {
    return totalPrice;
}

int Cart::getCartProductAmount(std::string ProductName) {
    for(auto it = cartProducts.begin(); it != cartProducts.end(); it++) {
        if(it->first->getProductName() == ProductName){
            return it->second;
        }
    }
}

void Cart::UpdateCartPrice(int ProdcutPrice,int DifferenceInProductAmount) {
    totalPrice += ProdcutPrice * DifferenceInProductAmount;
}

void Cart::setCartProducts(std::vector<std::pair<std::shared_ptr<Product>, int> > newCartProducts){
     cartProducts = newCartProducts;
}

void Cart::setTotalPrice(int newTotalPrice) {
     totalPrice = newTotalPrice;
}