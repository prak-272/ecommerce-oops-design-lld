#include "../include/Inventory.hpp"
#include<iostream>
#include<memory>
#include<utility>
#include<vector>
#include<iostream>

Inventory::Inventory() {}

void Inventory::addProduct(std::string ProductName,int ProductPrice,std::string ProdutType,int productAmount) {
    std::shared_ptr<Product> newProduct = std::shared_ptr<Product>(new Product(ProductName,ProductPrice,ProdutType));
    Products.push_back(std::make_pair(newProduct,productAmount));
    std::cout << "Product" << ProductName <<  "is added to the inventory";
}

void Inventory::removeProduct(std::string ProductName) {
    for(auto it = Products.begin(); it != Products.end(); it++) {
        if(it->first->getProductName() == ProductName) {
            Products.erase(it);
            std::cout << "Product" << ProductName << "is removed from Inventory";
            return;
        }
    }
    
    std::cout << "Product is not present in Inventory";
}

void Inventory::updateProductStock(std::string ProductName,int updateInAmount){
    for(auto it = Products.begin(); it != Products.end(); it++) {
        if(it->first->getProductName() == ProductName) {
            it->second += updateInAmount;
            std::cout << "Product" << ProductName << "stock updated in Inventory";
            return;
        }
    }
    
    std::cout << "Product" << ProductName << " is not present in Inventory";
}

void Inventory::updateProductPriceInInventory(std::string ProductName,int newProductPrice) {
    for(auto it = Products.begin(); it != Products.end(); it++) {
        if(it->first->getProductName() == ProductName) {
            it->first->setProductPrice(newProductPrice);
            std::cout << "Product" << ProductName << "Price updated in Inventory";
            return;
        }
    }

    std::cout << "Product" << ProductName << " is not present in Inventory";
}

int Inventory::getProductAmount(std::string ProductName) {
    for(auto it = Products.begin(); it != Products.end(); it++) {
        if(it->first->getProductName() == ProductName) {
            return it->second;
        }
    }
    return 0;
}

std::shared_ptr<Product> Inventory::getProduct(std::string ProductName) {
    for(auto it = Products.begin(); it != Products.end(); it++) {
        if(it->first->getProductName() == ProductName) {
            return it->first;
        }
    }
}

void Inventory::browseInventory() {
    for(auto it : Products ) {
        std::cout << "Product Name " << it.first->getProductName() << " Product Price " << it.first->getProductPrice() << " Product Type " << it.first->getProductType() << " Product Amount " << it.second <<  std::endl;          
    }
}

