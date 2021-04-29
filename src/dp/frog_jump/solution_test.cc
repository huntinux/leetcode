#include "solution.h"

#include "gtest/gtest.h"

TEST(message_test, content) {
  Solution s;
  EXPECT_EQ(1, s.FrogJump(1));
  EXPECT_EQ(2, s.FrogJump(2));
  EXPECT_EQ(3, s.FrogJump(3));
  EXPECT_EQ(5, s.FrogJump(4));
  EXPECT_EQ(8, s.FrogJump(5));
}

TEST(message_test_dp, content) {
  Solution s;
  EXPECT_EQ(1, s.FrogJumpDP(1));
  EXPECT_EQ(2, s.FrogJumpDP(2));
  EXPECT_EQ(3, s.FrogJumpDP(3));
  EXPECT_EQ(5, s.FrogJumpDP(4));
  EXPECT_EQ(8, s.FrogJumpDP(5));
}
