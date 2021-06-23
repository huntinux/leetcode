#include "solution.h"
#include "gtest/gtest.h"

TEST(test, case1) {
  std::vector<int> arr{4,5,6,7,8,1,2,3};
  Solution s;
  EXPECT_EQ(-1, s.search(arr, 0));
  EXPECT_EQ(4, s.search(arr, 8));
}

TEST(test, case2) {
  std::vector<int> arr{4,5,6,7,0,1,2};
  Solution s;
  EXPECT_EQ(4, s.search(arr, 0));
}

TEST(test, case3) {
  std::vector<int> arr{5,1,3};
  Solution s;
  EXPECT_EQ(2, s.search(arr, 3));
}
