#include "solution.h"

#include "gtest/gtest.h"

TEST(message_test,content)
{
  Solution s;
  vector<int> v1 {1, 2};
  vector<int> v2 {3};
  EXPECT_EQ(0, s.FindMedianSortedArrays(v1, v2));
}