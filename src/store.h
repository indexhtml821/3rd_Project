#ifndef STORE_H
#define STORE_H

#include <map>
#include <iostream>
#include <stdio.h>
#include <string>


#include "product.h"

using namespace std;
using namespace prod;

namespace stoe{
class Store
{
 
   

public:

  map<int, Product *> stockProducts;
    char storeName[20];
    char ip[24];
    char location[24];
    char phoneNumber[8];
 
    ~Store();
    Store(string name,
          string ip,
          string location,
          string phoneNumber);
    Store();
    // deletePlanilla();
    void addProduct(int id , Product *product);
    void modifyProductAmount(int id,int amount);
    string listProducts();
    void deleteProduct(int id);
    void storetoBinaryFile(ostream *storestream);
    void loadFromBinaryFile(istream *streamEntrada);
    friend ostream &operator<<(ostream &o, const Store *store);
    
};
}
#endif