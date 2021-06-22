#include "solution.h"

#include "gtest/gtest.h"

TEST(test, case1) {
  Solution s;
  vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}};
  auto res = s.spiralOrder(matrix);
  vector<int> expected{1, 2, 3, 6, 5, 4};
  EXPECT_EQ(res, expected);
}

TEST(test, case2) {
  Solution s;
  vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  auto res = s.spiralOrder(matrix);
  vector<int> expected{1, 2, 3, 6, 9, 8, 7, 4, 5};
  EXPECT_EQ(res, expected);
}

TEST(test, case3) {
  Solution s;
  vector<vector<int>> matrix = {{3}, {2}};
  auto res = s.spiralOrder(matrix);
  vector<int> expected{3, 2};
  EXPECT_EQ(res, expected);
}

TEST(test, case4) {
  Solution s;
  vector<vector<int>> matrix = {{3, 2}};
  auto res = s.spiralOrder(matrix);
  vector<int> expected{3, 2};
  EXPECT_EQ(res, expected);
}
