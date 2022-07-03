#ifndef STORE_H
#define STORE_H

#include <map>
#include <iostream>
#include <stdio.h>
#include <string>


#include "product.h"

using namespace std;

class Store
{
 
   

public:

  map<int, Product *> stockProducts;
    char storeName[15];
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
    
    void addProduct(Product *product);
    void modifyProductAmount(int id,int amount);
    void modifyProductName(int id,string name);
    string listProducts();
    void deleteProduct(int id);
    void storetoBinaryFile(ostream *storestream);
    void loadFromBinaryFile(istream *streamEntrada);
    friend ostream &operator<<(ostream &o, const Store *store);
    
};

#endif