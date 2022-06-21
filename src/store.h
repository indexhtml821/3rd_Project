#ifndef STORE_H
#define STORE_H

#include <vector>

#include "product.h"


using namespace std;

class Store
{

vector <Product *> stockProducts;


public:

void AddProduct(Product* product);
void modifyProduct(Product* product);
string listProducts();
void deleteProduct(Product* Product);
void storetoBinary(ostream *storestream);
void loadFromBinary(istream *streamEntrada);

  
};

#endif