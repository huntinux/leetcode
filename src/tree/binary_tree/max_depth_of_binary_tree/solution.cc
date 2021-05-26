#include "solution.h"

#include <queue>

int Solution::MaxDepth(TreeNode* root) {
  if (!root) return 0;
  return std::max(MaxDepth(root->left), MaxDepth(root->right)) + 1;
}

// 联想到binary tree level traversal的非递归实现
// 但是这个实现还有优化空间
int Solution::MaxDepthNonRecursion(TreeNode* root) {
  if (!root) return 0;
  int level = 1;
  int max_level = level;
  std::queue<std::pair<TreeNode*, int>> q;
  q.push(std::make_pair(root, level));
  while (!q.empty()) {
    const std::pair<TreeNode*, int>& p = q.front();
    TreeNode* node = p.first;
    int cur_level = p.second;
    if (cur_level > max_level) {
      max_level = cur_level;
    }
    if (node->left) q.push(std::make_pair(node->left, cur_level + 1));
    if (node->right) q.push(std::make_pair(node->right, cur_level + 1));
    q.pop();
  }
  return max_level;
}

int Solution::MaxDepthNonRecursion2(TreeNode* root) {
  if (!root) return 0;
  std::queue<TreeNode*> q;
  q.push(root);
  int level = 0;
  while(!q.empty()) {
    ++level;
    for (int i = 0, n = q.size(); i < n; ++i) {
      TreeNode* node = q.front();
      q.pop();
      if (node->left) q.push(node->left);
      if (node->right) q.push(node->right);
    }
  }
  return level;
}


// 来自leetcode的解法
// 很巧妙
// 每次清空当前层的元素，同时把当前层元素下一层的元素入队列
int maxDepth(TreeNode* root) {
  if (root == nullptr) return 0;

  int res = 0;
  std::queue<TreeNode*> q;
  q.push(root);
  while (!q.empty()) {
    ++res;  // 层次加一
    // 当前层的n个元素，出队列，同时把当前层元素的下一层所有元素都入队列
    for (int i = 0, n = q.size(); i < n; ++i) {
      TreeNode* p = q.front();
      q.pop();

      if (p->left != nullptr) q.push(p->left);
      if (p->right != nullptr) q.push(p->right);
    }
  }

  return res;
}
