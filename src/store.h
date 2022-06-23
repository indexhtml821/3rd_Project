#ifndef STORE_H
#define STORE_H

#include <vector>
#include <iostream>
#include <stdio.h>
#include <string>


#include "product.h"

using namespace std;

class Store
{
 
  public :  vector< Product *> stockProducts;
  public :  char storeName[20];
  public :  char ip[24];
  public :  char location[24];
  public :  char phoneNumber[8];

public:
 
    
    Store(string name,
          string ip,
          string location,
          string phoneNumber);
    Store();
    // deletePlanilla();
    void AddProduct(Product *product);
    void modifyProduct(Product *product);
    string listProducts();
    void deleteProduct(Product *Product);
    void storetoBinary(ostream *storestream);
    void loadFromBinary(istream *streamEntrada);
    friend ostream &operator<<(ostream &o, const Product *product);
};

#endif