#include "solution.h"

#include "gtest/gtest.h"

TEST(test, case1) {
  Solution s;
  vector<int> nums{2, 3, 1, 2, 4, 3};
  EXPECT_EQ(2, s.minSubArrayLen(7, nums));
}

TEST(test, case2) {
  Solution s;
  vector<int> nums{1, 4, 4};
  EXPECT_EQ(1, s.minSubArrayLen(4, nums));
}

TEST(test, case3) {
  Solution s;
  vector<int> nums{1, 1, 1, 1, 1, 1, 1, 1};
  EXPECT_EQ(0, s.minSubArrayLen(11, nums));
}
