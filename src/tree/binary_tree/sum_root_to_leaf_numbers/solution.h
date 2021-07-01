#pragma once

#include <vector>

using std::vector;

#include "src/tree/binary_tree/common/binary_tree.h"

/*
You are given the root of a binary tree containing digits from 0 to 9 only.

Each root-to-leaf path in the tree represents a number.

For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
Return the total sum of all root-to-leaf numbers. Test cases are generated so
that the answer will fit in a 32-bit integer.

A leaf node is a node with no children.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
 public:
  // Input: root = [1,2,3]
  // Output: 25
  // Explanation:
  // The root-to-leaf path 1->2 represents the number 12.
  // The root-to-leaf path 1->3 represents the number 13.
  // Therefore, sum = 12 + 13 = 25.
  int sumNumbers(TreeNode* root);

 private:
  void dfs(TreeNode* root, int& num, vector<int>& nums);
};
