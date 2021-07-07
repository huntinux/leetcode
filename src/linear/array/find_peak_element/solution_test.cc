#include "solution.h"

#include "gtest/gtest.h"

TEST(test, case1) {
  Solution s;
  vector<int> nums{1, 2, 3, 1};
  EXPECT_EQ(2, s.findPeakElement(nums));
}

TEST(test, case2) {
  Solution s;
  vector<int> nums{1, 2, 1, 3, 5, 6, 4};
  EXPECT_EQ(5, s.findPeakElement(nums));
}

