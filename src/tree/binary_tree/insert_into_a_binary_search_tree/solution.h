#pragma once

#include <vector>

#include "src/tree/binary_tree/common/binary_tree.h"

using TreeNode = binary_tree::TreeNode<int>;
using std::vector;

class Solution {
 public:
  // You are given the root node of a binary search tree (BST) and a value to
  // insert into the tree. Return the root node of the BST after the insertion.
  // It is guaranteed that the new value does not exist in the original BST.
  // Notice that there may exist multiple valid ways for the insertion, as
  // long as the tree remains a BST after insertion. You can return any of
  // them.
  //
  // Input: root = [40,20,60,10,30,50,70], val = 25
  // Output: [40,20,60,10,30,50,70,null,null,25]]]
  TreeNode* InsertIntoBST(TreeNode* root, int val);

  TreeNode* InsertIntoBST_NonRecursion(TreeNode* root, int val);
};

