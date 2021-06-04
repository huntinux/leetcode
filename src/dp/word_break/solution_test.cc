#include "solution.h"

#include "gtest/gtest.h"

TEST(test, case1) {
  Solution s;
  string str("leetcode");
  vector<string> dict{"leet", "code"};
  EXPECT_EQ(true, s.WordBreak(str, dict));
}
