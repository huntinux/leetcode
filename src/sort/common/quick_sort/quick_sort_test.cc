#include "quick_sort.h"
#include "gtest/gtest.h"

#include <iostream>

TEST(test, case1) {
  std::vector<int> v{5, 3, 2, 7, 6};
  quick_sort(v);
  std::vector<int> v2{2, 3, 5, 6, 7};
  EXPECT_EQ(v2, v);
}
