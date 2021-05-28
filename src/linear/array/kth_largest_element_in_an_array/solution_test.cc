#include "solution.h"

#include "gtest/gtest.h"

TEST(test, case1) {
  Solution s;
  std::vector<int> v{3,2,1,5,6,4};
  EXPECT_EQ(5, s.FindKthLargest(v, 2));
  std::vector<int> v2{3,2,3,1,2,4,5,5,6};
  EXPECT_EQ(4, s.FindKthLargest(v2, 4));
}
