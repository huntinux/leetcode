#include "solution.h"

// 解法1
//  第一遍扫描，记录那些行和列需要置零, 保持到数组或set中
//  第二遍根据上面的记录进行清零
//  这样时间复杂度为O(m*n), 空间杂度O(m+n)
// 
// 解法2
//  题目要求O(1)的空间复杂度，那么就思考可不可以用input代替上面的数组
//  因为如果扫描到某个位置matrix[i,j]为0时，第i行和第j列以后是要归零的，可以用作
//  辅助数组

void clear_row(vector<vector<int>>& matrix, int row) {
  const int kRowNum = matrix.size();
  const int kColumnNum = kRowNum > 0 ? matrix[0].size() : 0;
  for (int i = 0; i < kColumnNum; ++i) {
    matrix[row][i] = 0;
  }
}

void clear_column(vector<vector<int>>& matrix, int column) {
  const int kRowNum = matrix.size();
  const int kColumnNum = kRowNum > 0 ? matrix[0].size() : 0;
  for (int i = 0; i < kRowNum; ++i) {
    matrix[i][column] = 0;
  }
}

void Solution::setZeroes(vector<vector<int>>& matrix) {
  const int kRowNum = matrix.size();
  const int kColumnNum = kRowNum > 0 ? matrix[0].size() : 0;
  for (int i = 0; i < kRowNum; ++i) {
    for (int j = 0; j < kColumnNum; ++j) {
      if (matrix[i][j] == 0) {
        banned_rows_.insert(i);
        banned_columns_.insert(j);
      }
    }
  }

  for (int i = 0; i < kRowNum; ++i) {
    if (banned_rows_.find(i) != banned_rows_.end()) {
      clear_row(matrix, i);
    }
  }

  for (int i = 0; i < kColumnNum; ++i) {
    if (banned_columns_.find(i) != banned_columns_.end()) {
      clear_column(matrix, i);
    }
  }
}
