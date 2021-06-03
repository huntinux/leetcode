#pragma once

#include <vector>

#include "src/tree/binary_tree/common/binary_tree.h"

using TreeNode = binary_tree::TreeNode<int>;
using std::vector;

class Solution {
 public:
  int MinDepth(TreeNode* root);
  int MinDepthNonRecursion(TreeNode* root);
  int MinDepthNonRecursion2(TreeNode* root);
};

