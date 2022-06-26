#include <gtest/gtest.h>
#include "../src/product.h"
namespace
{
  TEST(Tests_Product, Test_empleadoNomina)
  {
    /// AAA

    // Arrange - configurar el escenario
   ostringstream streamTest;
    Product *coffe = new Product(1,
                                 500,
                                 "coffee");

    // Act - ejecute la operación`-
       streamTest << coffe;

       string result = streamTest.str();
       string required = "[1] - coffee 500" ;

    // Assert - valide los resultados
        EXPECT_EQ(result, required);
  }

}