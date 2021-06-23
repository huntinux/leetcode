#include "solution.h"

#include "gtest/gtest.h"

TEST(test, case1) {
  Solution s;
  EXPECT_EQ("bab", s.longestPalindrome("babad"));
  EXPECT_EQ("bb", s.longestPalindrome("cbbd"));
  EXPECT_EQ("a", s.longestPalindrome("a"));
}
