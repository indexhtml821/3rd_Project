#ifndef PRODUCT_H
#define PRODUCT_H
#include <stdio.h>
#include <iostream>
#include <string> // for string class
using namespace std;


class Product
{

   public: int productId ;
   public: int amount ;
   public: char prodName [20];

public:
    ~Product();

    Product( int productId ,
    int amount ,
    string name);
    Product();

    int getId();
    void setName(string name);

    friend ostream& operator << (ostream &o, const Product *product);

};

#endif