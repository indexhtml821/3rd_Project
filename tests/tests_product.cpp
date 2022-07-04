#include <gtest/gtest.h>
#include "../src/product.h"
#include "../src/exceptionValueOverflowMember.h"
using namespace std;

namespace
{

  TEST(Tests_Product, Test_getIdFunction)
  {
    /// AAA

    // Arrange -

    Product *coffee = new Product(1,
                                  500,
                                  "coffee");

    // Act -

    int result = coffee->getId();
    int required = 1;
    delete coffee;
    // Assert -
    EXPECT_EQ(result, required);
  }

  TEST(Tests_Product, Test_exceptionOnSetName)
  {
    /// AAA

    // Arrange -

    Product *coffee = new Product(1,
                                  500,
                                  "coffee");

    // Act -
    // Assert -
    EXPECT_THROW({ coffee->setName("cofeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee"); }, ExceptionValueOverflowMember);
  }

  TEST(Tests_Product, Test_exceptionValueOverflowMember)
  {
    /// AAA

    // Arrange -

    EXPECT_THROW({ Product *coffee = new Product(1,
                                                 500,
                                                 "coffeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee"); }, ExceptionValueOverflowMember);

    // Act -

    // Assert -
  }

  TEST(Tests_Product, Test_outputOperatorsOverload)
  {
    /// AAA

    // Arrange -
    ostringstream streamTest;
    Product *coffe = new Product(1,
                                 500,
                                 "coffee");

    // Act -
    streamTest << coffe;

    string result = streamTest.str();
    string required = "[1] - coffee 500";

    // Assert -
    EXPECT_EQ(result, required);
  }

}