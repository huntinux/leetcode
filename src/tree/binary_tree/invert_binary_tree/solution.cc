#include "solution.h"

TreeNode* Solution::invertTree(TreeNode* root) {
  if (root == nullptr) return nullptr;
  std::swap(root->left, root->right);
  invertTree(root->left);
  invertTree(root->right);
  return root;
}
