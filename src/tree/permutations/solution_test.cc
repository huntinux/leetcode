#include "solution.h"

#include "gtest/gtest.h"

static void debug_result(const vector<vector<int>>& res) {
  std::for_each(res.begin(), res.end(), [](const vector<int>& v) {
    std::cout << "[";
    for (int elem : v) {
      std::cout << elem << ",";
    }
    std::cout << "]" << std::endl;
  });
}

TEST(test, case1) {
  Solution s;
  vector<int> nums{1, 2, 3};
  auto res = s.permute(nums);
  EXPECT_EQ(6, res.size());
  debug_result(res);
}
