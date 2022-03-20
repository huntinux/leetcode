#pragma once

#include <vector>

#include "src/tree/binary_tree/common/binary_tree.h"

using TreeNode = binary_tree::TreeNode<int>;

class Codec {
 public:
  string serialize(TreeNode* root);

  // input: data = "1,2,3,N,N,4,5"
  // output: root
  TreeNode* deserialize(string data);
};
