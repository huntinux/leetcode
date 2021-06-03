#include "solution.h"
#include "gtest/gtest.h"

TEST(test, case1) {
  std::vector<int> arr{1, 2, 3, 4, 5};
  EXPECT_EQ(0, binary_search(arr, 1));
}

TEST(test, case2) {
  std::vector<int> arr;
  EXPECT_EQ(-1, binary_search(arr, 1));
}

TEST(test, case3) {
  std::vector<int> arr{1};
  EXPECT_EQ(0, binary_search(arr, 1));
}

TEST(test, case4) {
  std::vector<int> arr{1};
  EXPECT_EQ(-1, binary_search(arr, 2));
}
