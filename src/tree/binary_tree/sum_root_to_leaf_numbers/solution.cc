#include "solution.h"

// 一道非常典型的dfs(+状态回溯)应用题目, 遍历所有路径，最后求和集合

int Solution::sumNumbers(TreeNode* root) {
  vector<int> nums;
  int num = 0;
  dfs(root, num, nums);
  return std::accumulate(nums.begin(), nums.end(), 0);
}

void Solution::dfs(TreeNode* root, int& num, vector<int>& nums) {
  if (!root) return ;
  num = num * 10 + root->val;
  if (!root->left && !root->right) {
    nums.push_back(num);
  }
  dfs(root->left, num, nums);
  dfs(root->right, num, nums);
  num = (num - root->val) / 10; // 状态回溯
}
