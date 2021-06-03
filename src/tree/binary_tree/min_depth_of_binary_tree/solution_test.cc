#include "solution.h"

#include <sstream>
#include <vector>

#include "gtest/gtest.h"

TEST(test, case1) {
  TreeNode node1(3);
  TreeNode node2(9);
  TreeNode node3(20);
  TreeNode node4(15);
  TreeNode node5(7);

  node1.left = &node2;
  node1.right = &node3;
  node3.left = &node4;
  node4.right = &node5;

  Solution s;
  EXPECT_EQ(2, s.MinDepthNonRecursion2(&node1));
}
