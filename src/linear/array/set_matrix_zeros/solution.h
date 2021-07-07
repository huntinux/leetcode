#pragma once

#include <vector>

using std::vector;

class Solution {
 public:
  void setZeroes(vector<vector<int>>& matrix);
  void clear(vector<vector<int>>& matrix, int kRowNum, int kColumnNum, int row,
           int column);
 private:
  std::unordered_set<int> banned_rows_;
  std::unordered_set<int> banned_columns_;
};

