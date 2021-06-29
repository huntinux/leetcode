#include "solution.h"

#include "gtest/gtest.h"

TEST(test, case1) {
  Solution s;
  std::vector<int> v{3, 2, 1, 5, 6, 4};
  EXPECT_EQ(6, s.longestConsecutive(v));
}

TEST(test, case2) {
  Solution s;
  std::vector<int> v{100, 4, 200, 1, 3, 2};
  EXPECT_EQ(4, s.longestConsecutive(v));
}

TEST(test, case3) {
  Solution s;
  std::vector<int> v{0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
  EXPECT_EQ(9, s.longestConsecutive(v));
}
