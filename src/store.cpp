#include "store.h"
#include <string.h>
#include <stdio.h>
#include <iostream>

Store::Store(string name,
             string ip,
             string location,
             string phoneNumber)
{

strcpy(this->storeName,name.c_str());
strcpy(this->ip, ip.c_str());
strcpy(this->location,location.c_str());
strcpy(this->phoneNumber,phoneNumber.c_str());
}


void Store::AddProduct(Product* product){

  this->stockProducts.push_back(product);

}

 ostream& operator << (ostream &o, const Store *store)
{
    o << "Store stock: " << std::endl;
    int i =0;

    for (Product *product : store->stockProducts )
    {
        
        o << &product << endl;
    }
    
    return o;
}