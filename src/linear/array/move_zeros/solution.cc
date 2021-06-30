#include "solution.h"

// 分析
//   与题目“删除数组中重复元素类似”
void Solution::moveZeroes(vector<int>& nums) {
  int next_nonzero_pos = 0;
  for (int i = 0; i < nums.size(); ++i) {
    if (nums[i] != 0) {
      nums[next_nonzero_pos++] = nums[i];
    }
  }
  for (int i = next_nonzero_pos; i < nums.size(); ++i) {
    nums[i] = 0;
  }
}
