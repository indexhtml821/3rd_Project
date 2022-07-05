#include <gtest/gtest.h>
#include "../src/product.h"
#include "../src/store.h"
#include "../src/exceptionIdNotAllowed.h"
#include "../src/exceptionProductNameIsTaken.h"

#include <string>
#include <fstream>
#include <sstream>

using namespace std;

namespace
{
  TEST(Tests_Store, Test_addProduct)
  {
    /// AAA

    // Arrange -

    Product *product = new Product(1,
                                   500,
                                   "coffee");
    Store *store = new Store("mira",
                             "ip",
                             "location",
                             "phoneNumber");

    ostringstream streamTest;

    store->addProduct(product);

    // Act -

    streamTest << store;
    delete store;
    string result = streamTest.str();
    string required = "Store stock: \n[1] - coffee 500\n";

    // Assert -
    EXPECT_EQ(required, result);
  }

  TEST(Tests_Store, Test_addProductExceptionIdNotAllowed)
  {
    /// AAA

    // Arrange -

    Product *product = new Product(1,
                                   500,
                                   "coffee");

    Product *product1 = new Product(1,
                                    100,
                                    "donuts");

    Product *product2 = new Product(1,
                                    100,
                                    "donuts");

    Store *store = new Store("mira",
                             "ip",
                             "location",
                             "phoneNumber");

    // Act -
    store->addProduct(product);

    EXPECT_THROW({
      store->addProduct(product1);
    },
                 ExceptionIdNotAllowed);

    EXPECT_THROW({
      store->addProduct(product2);
    },
                 ExceptionIdNotAllowed);

    // Assert -
  }

  TEST(Tests_Store, Test_addProductExceptionProductNameIsTaken)
  {
    /// AAA

    // Arrange -

    Product *product = new Product(1,
                                   500,
                                   "coffee");

    Product *product1 = new Product(2,
                                    100,
                                    "Coffee");

     Store *store = new Store("mira",
                             "ip",
                             "location",
                             "phoneNumber");

    // Act -
    store->addProduct(product);

    // Assert -
    EXPECT_THROW({
      store->addProduct(product1);
    },
                 ExceptionProductNameIsTaken);

   
  }

  TEST(Tests_Store, Test_productAlreadyExists)
  {
    /// AAA

    // Arrange -

    Product *product = new Product(1,
                                   500,
                                   "coffee");

    Store *store = new Store("mira",
                             "ip",
                             "location",
                             "phoneNumber");

    // Act -
    store->addProduct(product);
    bool result = store->productAlreadyExists("Coffee");
    bool required = true;

    // Assert -
    EXPECT_EQ(required, result);
  }
  TEST(Tests_Store, Test_modifyProductAmount)
  {
    /// AAA

    // Arrange -

    Product *product = new Product(1,
                                   500,
                                   "coffee");
    Store *store = new Store("mira",
                             "ip",
                             "location",
                             "phoneNumber");

    ostringstream streamTest;

    store->addProduct(product);

    // Act -
    store->modifyProductAmount(1, 200);

    streamTest << store;
    string result = streamTest.str();
    string required = "Store stock: \n[1] - coffee 200\n";

    // Assert -
    EXPECT_EQ(required, result);
  }
  TEST(Tests_Store, Test_modifyProductName)
  {
    /// AAA

    // Arrange -

    Product *product = new Product(1,
                                   500,
                                   "coffee");
    Store *store = new Store("mira",
                             "ip",
                             "location",
                             "phoneNumber");

    ostringstream streamTest;

    store->addProduct(product);

    // Act -
    store->modifyProductName(1, "cookies");

    streamTest << store;
    string result = streamTest.str();
    string required = "Store stock: \n[1] - cookies 500\n";

    // Assert -
    EXPECT_EQ(required, result);
  }

  TEST(Tests_Store, Test_listProducts)
  {
    /// AAA

    // Arrange -

    Product *product = new Product(1,
                                   500,
                                   "coffee");

    Product *product1 = new Product(2,
                                    500,
                                    "cookies");
    Store *store = new Store("mira",
                             "ip",
                             "location",
                             "phoneNumber");

    ostringstream streamTest;

    store->addProduct(product);
    store->addProduct(product1);

    // Act -

    vector<Product *> vectorResult = store->listProducts();
    for (Product *productRead : vectorResult)
    {

      streamTest << productRead << endl;
    }

    string result = streamTest.str();
    string required = "[1] - coffee 500\n[2] - cookies 500\n";

    // Assert -
    EXPECT_EQ(required, result);
  }

  TEST(Tests_Store, Test_deleteProduct)
  {
    /// AAA

    // Arrange -

    Product *product = new Product(1,
                                   500,
                                   "coffee");
    Store *store = new Store("mira",
                             "ip",
                             "location",
                             "phoneNumber");

    ostringstream streamTest;

    store->addProduct(product);

    // Act -
    store->deleteProduct(1);

    streamTest << store;
    string result = streamTest.str();
    string required = "Store stock: \n";

    // Assert -
    EXPECT_EQ(required, result);
  }

  TEST(Tests_Store, Test__store_load_from_Binary)
  {

    // Writing the binary file
    /// AAA

    // Arrange -

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
    // Act -

    // writing the binary file
    storeExpected->addProduct(product);

    fileTest.open("test_file.dat", ios::out | ios::binary);

    if (!fileTest.is_open())
    {
      cerr << " test_file.dat can´t be opened to write the data";
      FAIL();
    }

    storeExpected->storetoBinaryFile(&fileTest);

    fileTest.close();

    // Reading the binary file

    fileLoadTest.open("test_file.dat", ios::in | ios::binary);

    if (!fileLoadTest.is_open())
    {
      cerr << "test_file.dat can´t be opened to read the data";
      FAIL();
    }

    storeToRead->loadFromBinaryFile(&fileLoadTest);

    streamOutputReadedStore << storeToRead;

    streamStoreOutputExpected << storeExpected;

    delete storeToRead;
    delete storeExpected;

    string required = "Store stock: \n[1] - coffee 500\n";
    string stringStoreOutputExpected = streamStoreOutputExpected.str();
    // Assert -

    EXPECT_EQ(required, stringStoreOutputExpected);

    string resultstringStoreOutputExpectedFromFile = streamStoreOutputExpected.str();

    EXPECT_EQ(required, resultstringStoreOutputExpectedFromFile);
  }

}