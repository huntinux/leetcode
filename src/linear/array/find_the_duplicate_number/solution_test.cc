#include "solution.h"

#include "gtest/gtest.h"

TEST(test, case1) {
  Solution s;
  vector<int> nums{1, 3, 4, 2, 2};
  EXPECT_EQ(2, s.findDuplicate(nums));
}

TEST(test, case2) {
  Solution s;
  vector<int> nums{3, 1, 3, 4, 2};
  EXPECT_EQ(3, s.findDuplicate(nums));
}

TEST(test, case3) {
  Solution s;
  vector<int> nums{1, 1};
  EXPECT_EQ(1, s.findDuplicate(nums));
}
