#include "solution.h"

// 递归写法
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
  if (!root || p == root || q == root) return root;
  TreeNode* left = lowestCommonAncestor(root->left, p, q);
  TreeNode* right = lowestCommonAncestor(root->right, p, q);
  if (left == nullptr && right == nullptr) return nullptr;
  if (left != nullptr && right != nullptr) return root;
  return left == nullptr ? right : left;
}
