#include <gtest/gtest.h>
#include "../src/product.h"
#include "../src/store.h"

namespace
{
  TEST(Tests_Store, Test_printProduct)
  {
    /// AAA

    // Arrange - configurar el escenario

    // EmpleadoNomina empleadonomina(1, "Denis", "Tyler", "denis_tyler@biz.com", 1, 1, 4000.67);

    Store *store = new Store("mira",
                             "ip",
                             "location",
                             "phoneNumber");

    // Act - ejecute la operación`-

    Product *coffe = new Product(1,
                                 500,
                                 "coffee");
    store->AddProduct(coffe);
    ostringstream streamTest;
    streamTest << store;
    string result = streamTest.str();
    string required = "1 500 coffee";

    // Assert - valide los resultados
    EXPECT_EQ(required, result);
  }

}