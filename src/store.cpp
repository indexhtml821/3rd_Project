#include "store.h"
#include <string.h>
#include <stdio.h>
#include <iostream>

Store::~Store()
{
}

Store::Store(string name,
             string ip,
             string location,
             string phoneNumber)
{

  strcpy(this->storeName, name.c_str());
  strcpy(this->ip, ip.c_str());
  strcpy(this->location, location.c_str());
  strcpy(this->phoneNumber, phoneNumber.c_str());
}

Store::Store()
{
}

void Store::addProduct(int id, Product *product)
{

  this->stockProducts.insert(std::pair<int, Product *>(id, product));
}

void Store::modifyProductAmount(int id,int amount)
{

   stockProducts.at(id)->amount =amount;

}
/* NECESARIO?
string Store:: listProducts(){

    auto iter =this->stockProducts.begin();
    int index = 0;
    string listado ="";

    while (iter != this->stockProducts.end() )
    {

       lista  this->stockProducts.at(index) << endl;
    }


};
*/

void Store::deleteProduct(int id)
{

  stockProducts.erase(id);
}

void Store::storetoBinaryFile(ostream *storestream)
{
   Store *store = new Store(this->storeName,this->ip,this->location,this->phoneNumber);

    storestream->write((char *)store , sizeof(Product));

  auto iter = stockProducts.begin();

  while (iter != stockProducts.end())
  {
    storestream->write((char *)iter->second, sizeof(Product));

    iter++;
  }
}

void Store::loadFromBinaryFile(istream *loadStream)
{



  loadStream->seekg(0, std::ios::end);
  int fileByteAmount = loadStream->tellg();
  int productsAmount = fileByteAmount / sizeof(Product);

  // Leer cada empleado
  loadStream->seekg(0, std::ios::beg); // Empezar desde el principio del archivo
  for (int indice = 0; indice < productsAmount; indice++)
  {
    Product *product = new Product();
    loadStream->read((char *)product, sizeof(Product)); // variable para guardar y cuántos bytes leo
    int id = product->productId;
    this->addProduct(id, product);
  }
}
ostream &operator<<(ostream &o, const Store *store)
{
  o << "Store stock: " << std::endl;
  auto iter = store->stockProducts.begin();

  while (iter != store->stockProducts.end())
  {
    o << iter->second << endl;
    iter++;
  }

  return o;
}