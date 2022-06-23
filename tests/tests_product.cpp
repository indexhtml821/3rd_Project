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

       string actual = streamTest.str();
       string esperada = "[1] - 500 coffee" ;

    // Assert - valide los resultados
        EXPECT_EQ(esperada, actual);
  }

}