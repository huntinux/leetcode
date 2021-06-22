#include "solution.h"

#include "gtest/gtest.h"

TEST(test, case1) {
  //std::vector<int> arr{1, 3, 2, 3, 1};
  std::vector<int> arr{7, 5, 6, 4};
  Solution s;
  EXPECT_EQ(5, s.ReversePairs(arr));
}
