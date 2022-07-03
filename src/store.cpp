#include "store.h"
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <sstream>
#include "exceptionIdNotAllowed.h"

Store::~Store()
{

  this->stockProducts.erase(stockProducts.begin(), this->stockProducts.end());
}

Store::Store(string name,
             string internetAddress,
             string location,
             string phoneNumber)
{

  strcpy(this->storeName, name.c_str());
  strcpy(this->internetAddress, internetAddress.c_str());
  strcpy(this->location, location.c_str());
  strcpy(this->phoneNumber, phoneNumber.c_str());
}

Store::Store()
{
}

void Store::addProduct(Product *product)
{
  if (stockProducts.count(product->getId()))
  {

    throw ExceptionIdNotAllowed();
    return;
  }
  if (product->getId() < 0)
  {
    throw ExceptionIdNotAllowed();
    return;
  }

  this->stockProducts.insert(std::pair<int, Product *>(product->getId(), product));
}

void Store::modifyProductAmount(int id, int amount)
{
  if (id < 0)
  {
    throw ExceptionIdNotAllowed();
    return;
  }

  if (stockProducts.count(id))
  {

    stockProducts.at(id)->setAmount(amount);
    return;
  }
  else
  {
    throw ExceptionIdNotAllowed();
    return;
  }
}

void Store::modifyProductName(int id, string name)
{
  if (id < 0)
  {
    throw ExceptionIdNotAllowed();
    return;
  }

  if (stockProducts.count(id))
  {
    stockProducts.at(id)->setName(name);
    return;
  }
  else
  {
    throw ExceptionIdNotAllowed();
    return;
  }
}

string Store::listProducts()
{

  auto iter = this->stockProducts.begin();
  string list = "";
  ostringstream listing;

  while (iter != this->stockProducts.end())
  {
    listing << iter->second << endl;
    iter++;
  }
  list = listing.str();
  return list;
};

void Store::deleteProduct(int id)
{
  if (id < 0)
  {
    throw ExceptionIdNotAllowed();
    return;
  }

  if (stockProducts.count(id))
  {
    stockProducts.erase(id);
    return;
  }
  else
  {
    throw ExceptionIdNotAllowed();
    return;
  }
}

void Store::storetoBinaryFile(ostream *storestream)
{
  storestream->write(this->storeName, sizeof(this->storeName));
  storestream->write(this->internetAddress, sizeof(this->internetAddress));
  storestream->write(this->location, sizeof(location));
  storestream->write(this->phoneNumber, sizeof(phoneNumber));

  auto iter = stockProducts.begin();

  while (iter != stockProducts.end())
  {
    storestream->write((char *)iter->second, sizeof(Product));

    iter++;
  }
}

void Store::loadFromBinaryFile(istream *loadStream)
{
  int headerSize = sizeof(this->storeName) + sizeof(this->internetAddress) + sizeof(this->location) + sizeof(this->phoneNumber);
  loadStream->seekg(0, std::ios::end);
  int fileByteAmount = loadStream->tellg();
  int productsAmount = (fileByteAmount - headerSize) / sizeof(Product);

  // Leer cada empleado
  loadStream->seekg(0, std::ios::beg); // Empezar desde el principio del archivo
  loadStream->read((char *)this->storeName, sizeof(this->storeName));
  loadStream->read((char *)this->internetAddress, sizeof(this->internetAddress));
  loadStream->read((char *)this->location, sizeof(this->location));
  loadStream->read((char *)this->phoneNumber, sizeof(this->phoneNumber));

  for (int indice = 0; indice < productsAmount; indice++)
  {
    Product *product = new Product();
    loadStream->read((char *)product, sizeof(Product)); // variable para guardar y cuántos bytes leo
    this->addProduct(product);
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