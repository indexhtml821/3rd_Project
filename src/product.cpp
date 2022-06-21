#include "product.h"
#include <string.h>

Product::Product(int productId,
                 int amount,
                 string name)
{
    this->productId = productId;
    this->amount = amount;
    char prodName [20]; 
    strcpy(this->prodName,name.c_str());
   
}

Product::Product()
{
    this->productId = 0;
    this->amount = 0;
    strcpy(this->prodName, "");
}

ostream& operator << (ostream &o, const Product *product)
{
    o << "[" << product->productId << "] - " << product->amount << " " << product->prodName;  
    return o;
}