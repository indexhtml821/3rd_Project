#ifndef PRODUCT_H
#define PRODUCT_H
#include <stdio.h>
#include <iostream>
#include <string> // for string class
using namespace std;

namespace prod{
class Product
{

   public: int productId ;
   public: int amount ;
    char prodName [20];

public:
    ~Product();

    Product( int productId ,
    int amount ,
    string name);
    Product();

    friend ostream& operator << (ostream &o, const Product *product);

};
}
#endif