#pragma once

namespace binary_tree {

/**
 * Definition for a binary tree node.
 */
template <typename T>
struct TreeNode {
  T val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

// TODO
// 1 -1 2 3 4
TreeNode<int>* BuildBinaryTree(const std::vector<int>& elems);

}  // namespace binary_tree
