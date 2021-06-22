#pragma once

#include <vector>

#include "src/tree/binary_tree/common/binary_tree.h"

using TreeNode = binary_tree::TreeNode<int>;
using std::vector;

class Solution {
 public:
  bool isBalanced(TreeNode* root);
};
