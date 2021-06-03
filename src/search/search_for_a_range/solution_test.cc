#include "solution.h"
#include "gtest/gtest.h"

TEST(test, case1) {
  std::vector<int> arr;
  Solution s;
  EXPECT_EQ(-1, s.lower_bound(arr, 0));
  EXPECT_EQ(-1, s.upper_bound(arr, 0));
}

TEST(test, case2) {
  std::vector<int> arr{1, 2, 2, 2, 5};
  Solution s;
  EXPECT_EQ(1, s.lower_bound(arr, 2));
  EXPECT_EQ(-1, s.lower_bound(arr, 3));
  EXPECT_EQ(0, s.lower_bound(arr, 1));
  EXPECT_EQ(4, s.lower_bound(arr, 5));
  EXPECT_EQ(3, s.upper_bound(arr, 2));
}

TEST(test, case3) {
  std::vector<int> arr{1};
  Solution s;
  EXPECT_EQ(-1, s.lower_bound(arr, 0));
  EXPECT_EQ(-1, s.upper_bound(arr, 0));
  std::vector<int> r = s.SearchRange(arr, 0);
  EXPECT_EQ(2, r.size());
  EXPECT_EQ(-1,r[0]);
  EXPECT_EQ(-1,r[1]);
}


