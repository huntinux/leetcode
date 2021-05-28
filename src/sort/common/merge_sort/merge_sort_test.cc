#include "merge_sort.h"
#include "gtest/gtest.h"

#include <iostream>

TEST(test, case1) {
  std::vector<int> v{5, 3, 2, 7, 6};
  auto v_sorted = merge_sort(v);
  std::vector<int> v2{2, 3, 5, 6, 7};
  EXPECT_EQ(v2, v_sorted);

  merge_sort_non_recursion(v);
  EXPECT_EQ(v2, v);
}
