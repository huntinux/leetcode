#include "solution.h"

#include <queue>

// 递归版本
TreeNode* Solution::InsertIntoBST(TreeNode* root, int val) {
  if (!root) {
    TreeNode* node = new TreeNode(val);
    return node;
  }
  if (val < root->val) {
    root->left = InsertIntoBST(root->left, val);
  } else {
    root->right = InsertIntoBST(root->right, val);
  }
  return root;
}

// 迭代版本
//
// 思路很简单，就是比较val与root->val的关系，
TreeNode* Solution::InsertIntoBST_NonRecursion(TreeNode* root, int val) {
  TreeNode* target = new TreeNode(val);
  if (!root) return target;

  TreeNode* node = root;
  while (node) {
    if (val < node->val) {
      if (node->left) {
        node = node->left;
      } else {
        node->left = target;
        break;
      }
    } else {
      if (node->right) {
        node = node->right;
      } else {
        node->right = target;
        break;
      }
    }
  }
  return root;
}

// leetcode 
//
// 指针迭代,很精妙
TreeNode* insertIntoBST(TreeNode* root, int val) {
  TreeNode** cur = &root;
  while (*cur) cur = (val > (*cur)->val) ? &(*cur)->right : &(*cur)->left;
  *cur = new TreeNode(val);
  return root;
}
