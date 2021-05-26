#pragma once

#include <vector>

#include "src/tree/binary_tree/common/binary_tree.h"

using TreeNode = binary_tree::TreeNode<int>;
using std::vector;

class Solution {
 public:
  int MaxDepth(TreeNode* root);
  int MaxDepthNonRecursion(TreeNode* root);
  int MaxDepthNonRecursion2(TreeNode* root);
};

