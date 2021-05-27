#include "solution.h"

#include "gtest/gtest.h"

TEST(test, case1) {
  Solution s;
  EXPECT_EQ(16, s.atoi("16"));
  EXPECT_EQ(16, s.atoi("16.0"));
  EXPECT_EQ(16, s.atoi("   16"));
  EXPECT_EQ(-16, s.atoi("   -16"));
  EXPECT_EQ(16, s.atoi("   +16"));
  EXPECT_EQ(4193, s.atoi("4193 with words"));
  EXPECT_EQ(-2147483648, s.atoi("-91283472332"));
  EXPECT_EQ(2147483647, s.atoi("20000000000000000000"));
  EXPECT_EQ(12345678, s.atoi("  0000000000012345678"));
}
