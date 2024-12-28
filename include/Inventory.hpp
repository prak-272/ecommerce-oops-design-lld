#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include<string>
#include<vector>
#include<utility>
#include<memory>
#include "Product.hpp"

class Inventory {
private: 
   std::vector<std::pair<std::shared_ptr<Product>, int> > Products;

public:
   Inventory();
   void addProduct(std::string ProductName,int ProductPrice,std::string ProductType,const int productAmount);
   void removeProduct(std::string ProductName);  
   void updateProductStock(std::string ProductName,int updateInAmount);
   void updateProductPriceInInventory(std::string ProductName,int newProductPrice);
   int getProductAmount(std::string ProductName);
   std::shared_ptr<Product> getProduct(std::string ProductName);
   void browseInventory();
};

#endif