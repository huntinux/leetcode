#include "solution.h"

#include "gtest/gtest.h"

TEST(test, case1) {
  Solution s;
  vector<int> nums{1, 1, 1};
  EXPECT_EQ(2, s.subarraySum(nums, 2));
}

TEST(test, case2) {
  Solution s;
  vector<int> nums{1, 2, 3};
  EXPECT_EQ(2, s.subarraySum(nums, 3));
}

TEST(test, case3) {
  Solution s;
  vector<int> nums{1};
  EXPECT_EQ(1, s.subarraySum(nums, 1));
  EXPECT_EQ(0, s.subarraySum(nums, 0));
}

TEST(test, case4) {
  Solution s;
  vector<int> nums{-1, -1, 1};
  EXPECT_EQ(1, s.subarraySum(nums, 0));
}
