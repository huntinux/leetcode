#include "solution.h"

inline bool IsValidPosition(int x, int y, int x_min, int x_max, int y_min,
                            int y_max) {
  return x >= x_min && x <= x_max && y >= y_min && y <= y_max;
}

// 分析
// 其实就是控制坐标，上下左右边界随着遍历不断收敛
//
// 坐标为下所示
// ----> x
// |
// |
// V
// y

// ref: https://leetcode-cn.com/problems/spiral-matrix/solution/dong-hua-mo-ni-yi-xia-jiu-neng-gao-dong-i27qf/
vector<int> Solution::spiralOrder(vector<vector<int>>& matrix) {
  vector<int> result;
  if (matrix.size() == 0) return result;
  int top = 0, down = matrix.size() - 1, left = 0, right = matrix[0].size() - 1;
  while (true) {
    for (int i = left; i <= right; ++i) {
      result.push_back(matrix[top][i]);
    }
    top++;
    if (top > down) break;

    for (int i = top; i <= down; ++i) {
      result.push_back(matrix[i][right]);
    }
    right--;
    if (left > right) break;

    for (int i = right; i >= left; --i) {
      result.push_back(matrix[down][i]);
    }
    down--;
    if (top > down) break;

    for (int i = down; i >= top; --i) {
      result.push_back(matrix[i][left]);
    }
    left++;
    if (left > right) break;
  }

  return result;
}

/*
vector<int> Solution::spiralOrder(vector<vector<int>>& matrix) {
  vector<int> res;
  if (matrix.size() == 0) return res;

  int x_min = 0;
  int x_max = matrix[0].size() - 1;
  int y_min = 0;
  int y_max = matrix.size() - 1;
  int x = 0, y = 0;

  res.reserve((x_max + 1) * (y_max + 1));
  while (true) {
    while (x <= x_max) {
      res.push_back(matrix[y][x]);
      ++x;
    }
    // 调整到下一个可能的位置
    --x;
    ++y;
    // 校验该位置是否合法
    if (!IsValidPosition(x, y, x_min, x_max, y_min, y_max)) break;
    x_max -= 1;  // x轴的最大边界收敛一个坐标

    while (y <= y_max) {
      res.push_back(matrix[y][x]);
      ++y;
    }
    --y;
    --x;
    if (!IsValidPosition(x, y, x_min, x_max, y_min, y_max)) break;
    y_max -= 1;

    while (x >= x_min) {
      res.push_back(matrix[y][x]);
      --x;
    }
    ++x;
    --y;
    if (!IsValidPosition(x, y, x_min, x_max, y_min, y_max)) break;
    x_min += 1;

    while (y > y_min) {
      res.push_back(matrix[y][x]);
      --y;
    }
    ++y;
    ++x;
    if (!IsValidPosition(x, y, x_min, x_max, y_min, y_max)) break;
    y_min += 1;
  }

  return res;
}
*/


