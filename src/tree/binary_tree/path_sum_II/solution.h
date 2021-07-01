#pragma once

#include <vector>

using std::vector;

#include "src/tree/binary_tree/common/binary_tree.h"
/*
Given the root of a binary tree and an integer targetSum, return all
root-to-leaf paths where each path's sum equals targetSum.

A leaf is a node with no children
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
  vector<vector<int>> pathSum(TreeNode* root, int targetSum);
 private:
  void dfs(TreeNode* root, int targetSum, vector<int>& path);
 private:
  vector<vector<int>> result_;
};
