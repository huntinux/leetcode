#include "solution.h"

#include "gtest/gtest.h"

TEST(test, case1) {
  Solution s;
  EXPECT_EQ(3, s.longestCommonSubsequence("abcde", "ace"));
  EXPECT_EQ(3, s.longestCommonSubsequence("abc", "abc"));
  EXPECT_EQ(0, s.longestCommonSubsequence("abc", "def"));
}
