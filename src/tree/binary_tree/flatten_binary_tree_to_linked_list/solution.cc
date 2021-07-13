#include "solution.h"

// 利用先序遍历的非递归实现
// 同时结合list的尾插法
//
// example: root = [1,2,5,3,4,null,6]
//
// stack: [1
//        [5, 2  | tail = 1
//        [5, 4, 3 | node = 2  1->2 tail = 2
void Solution::flatten(TreeNode* root) {
  TreeNode* tail = nullptr;
  std::stack<TreeNode*> s;
  if (root) s.push(root);
  while (!s.empty()) {
    TreeNode* node = s.top();
    s.pop();
    if (node->right) s.push(node->right);
    if (node->left) s.push(node->left);
    if (tail) {
      tail->right = node;
      tail->left = nullptr;
      tail = node;
    } else {
      tail = node;
    }
  }
}

