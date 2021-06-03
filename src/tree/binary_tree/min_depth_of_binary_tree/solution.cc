#include "solution.h"

#include <bits/stdc++.h>

#include <queue>
#include <stack>

int Solution::MinDepth(TreeNode* root) {
  if (!root) return 0;
  return std::min(MinDepth(root->left), MinDepth(root->right)) + 1;
}

// 问题等价于找深度最低的叶子节点
// 结合二叉树遍历的非递归方式实现
// 结合先序遍历（stack）, stack中的元素额外记录当前节点的深度
int Solution::MinDepthNonRecursion(TreeNode* root) {
  if (!root) return 0;
  std::stack<std::pair<TreeNode*, int>> s;
  s.push(std::make_pair(root, 1));
  int result = INT_MAX;
  while (!s.empty()) {
    TreeNode* cur = s.top().first;
    int depth = s.top().second;
    s.pop();

    if (!cur->left && !cur->right) {
      result = std::min(result, depth);
    }

    if (cur->left && depth < result)  // 深度控制，剪枝
      s.push(std::make_pair(cur->left, depth + 1));

    if (cur->right && depth < result)
      s.push(std::make_pair(cur->right, depth + 1));
  }
  return result;
}

// 结合层次遍历
// 效率没有上面先序遍历高，因为先序遍历有剪枝操作
int Solution::MinDepthNonRecursion2(TreeNode* root) {
  if (!root) return 0;
  std::queue<TreeNode*> q;
  int current_max_level = 0;
  q.push(root);
  while (!q.empty()) {
    ++current_max_level;
    for (int i = 0, n = q.size(); i < n; ++i) {
      TreeNode* cur = q.front();
      q.pop();
      if (!cur->left && !cur->right) {  // 这一层有叶子节点，它的高度即为答案
        return current_max_level;
      }
      if (cur->left) q.push(cur->left);
      if (cur->right) q.push(cur->right);
    }
  }
  return current_max_level;
}
