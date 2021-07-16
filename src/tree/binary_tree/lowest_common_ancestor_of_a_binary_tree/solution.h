#pragma once

#include <vector>

#include "src/tree/binary_tree/common/binary_tree.h"

using TreeNode = binary_tree::TreeNode<int>;
using std::vector;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
 public:
  // 所有 Node.val 互不相同 。
  // p != q
  // p 和 q 均存在于给定的二叉树中。
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q);
};
