#include "solution.h"

#include "gtest/gtest.h"

TEST(test, case1) {
  std::vector<int> arr{1, 3, 2, 3, 1};
  Solution s;
  EXPECT_EQ(2, s.ReversePairs(arr));
}

TEST(test, case2) {
  std::vector<int> arr{2, 4, 3, 5, 1};
  Solution s;
  EXPECT_EQ(3, s.ReversePairs(arr));
}
