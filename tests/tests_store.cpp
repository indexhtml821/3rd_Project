#include <gtest/gtest.h>
#include "../src/product.h"
#include "../src/store.h"

#include <string>
#include <fstream>
#include <sstream>

namespace
{
  TEST(Tests_Store, Test_addProduct)
  {
    /// AAA

    // Arrange - configurar el escenario

    Product *product = new Product(1,
                                 500,
                                 "coffee");
    Store *store = new Store("mira",
                             "ip",
                             "location",
                             "phoneNumber");

    ostringstream streamTest;

    store->addProduct(1, product);

    // Act - ejecute la operación`-

    streamTest << store;
    string result = streamTest.str();
    string required = "Store stock: \n[1] - coffee 500\n";

    // Assert - valide los resultados
    EXPECT_EQ(required, result);
  }

  TEST(Tests_Store, Test__store_load_from_Binary)
  {

    // Writing the binary file
    /// AAA

    // Arrange - test scenario configuration

    Product *product = new Product(1,
                                 500,
                                 "coffee");
    Store *storeExpected = new Store("mira",
                                     "ip",
                                     "location",
                                     "phoneNumber");
    Store *storeToRead = new Store();
    ofstream fileTest;

    ifstream fileLoadTest;

    ostringstream streamOutputReadedStore;

    ostringstream streamStoreOutputExpected;
    // Act - operation execution



     //writing the binary file
    storeExpected->addProduct(1, product);
    
    fileTest.open("test_file.dat", ios::out | ios::binary);

    if (!fileTest.is_open())
    {
      cerr << "No se pudo abrir archivo archivo_test.dat para escribir los datos";
      FAIL();
    }

    storeExpected->storetoBinaryFile(&fileTest);

    fileTest.close();

    // Reading the binary file

    fileLoadTest.open("test_file.dat", ios::in | ios::binary);

    if (!fileLoadTest.is_open())
    {
      cerr << "No se pudo abrir archivo archivo_test.dat para leer los datos";
      FAIL();
    }

    storeToRead->loadFromBinaryFile(&fileLoadTest);

    streamOutputReadedStore << storeToRead;

    streamStoreOutputExpected << storeExpected;

    delete storeToRead;
    delete storeExpected;

    string required = "Store stock: \n[1] - coffee 500\n";
    string stringStoreOutputExpected = streamStoreOutputExpected.str();
    // Assert - check results
    // Primero, validar la salida de la planilla esperada sea correcta
    EXPECT_EQ(required, stringStoreOutputExpected);

    string resultstringStoreOutputExpectedFromFile = streamStoreOutputExpected.str();
 
    EXPECT_EQ(required, resultstringStoreOutputExpectedFromFile);
  }

}