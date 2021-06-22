#pragma once

#include <stack>
#include <vector>

using std::stack;
using std::vector;

class Solution {
 public:
  // Input: nums = [1,2,3]
  // Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
  vector<vector<int>> permute(vector<int>& nums);

 private:
  //void dfs(vector<int>& nums, int depth, vector<bool>& used, stack<int>& path,
  //         vector<vector<int>>& res);
  void dfs(vector<int>& nums, int depth, vector<bool>& used, vector<int>& path,
           vector<vector<int>>& res);
};
