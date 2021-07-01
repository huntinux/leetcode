#include "solution.h"

// 此题目是path sum的扩展，需要返回所有路径和为targetSum的path集合
// 基本思路还是借助dfs，遍历所有路径，同时记录path，如果到达叶子节点，
// 且路径和满足要求, 就将此path加入结果
// 想象叶子节点有两个nullptr的子树
vector<vector<int>> Solution::pathSum(TreeNode* root, int targetSum) {
  vector<int> path;
  dfs(root, targetSum, path);
  return result_;
}

void Solution::dfs(TreeNode* root, int targetSum, vector<int>& path) {
  if (!root) return;

  // 加入当前节点到path中，并更新targetSum
  path.push_back(root->val);
  targetSum -= root->val;

  // 到达叶子节点，如果满足要求，就将此路径path加入result
  if (!root->left && !root->right && 0 == targetSum) {
    result_.push_back(path);
  }

  // 对左右子树执行同样的过程，以遍历所有路径
  dfs(root->left, targetSum, path);
  dfs(root->right, targetSum, path);

  // path为dfs中的状态变量，需要回溯
  path.pop_back();
  targetSum += root->val;
}
