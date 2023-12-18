#include "product.h"
#include <gtest/gtest.h>

TEST(ProductTest, CorrectCreate) {

  Product p{1, "Молоко", 25.50, 10};
  
  EXPECT_EQ(p.id, 1);
  EXPECT_EQ(p.name, "Молоко");
  EXPECT_FLOAT_EQ(p.price, 25.50);
  EXPECT_EQ(p.quantity, 10);
}

TEST(ProductTest, ValidateFields) {

  EXPECT_THROW(Product p{1, "", 0, -5}, std::invalid_argument);  

  Product p{1, "Хлеб", 10.80, 5});
  EXPECT_NO_THROW(p.validate());
}