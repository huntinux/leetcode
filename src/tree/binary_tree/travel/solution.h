#pragma once

#include <vector>

#include "src/tree/binary_tree/common/binary_tree.h"

using TreeNode = binary_tree::TreeNode<int>;
using std::vector;

class Solution {
 public:
  // 递归实现
  vector<int> PreorderTraversalRecursion(TreeNode *root);
  vector<int> InorderTraversalRecursion(TreeNode *root);
  vector<int> PostorderTraversalRecursion(TreeNode *root);

  void PreorderTraversalRecursionHelper(TreeNode *root, vector<int> *result);

  // 非递归实现
  vector<int> PreorderTraversalNonRecursion(TreeNode *root);
  vector<int> InorderTraversalNonRecursion(TreeNode *root);
  vector<int> PostorderTraversalNonRecursion(TreeNode *root);
  vector<vector<int>> LevelorderTraversal(TreeNode *root);
};

