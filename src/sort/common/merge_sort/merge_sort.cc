#include "merge_sort.h"

#include <cstdlib>
#include <iostream>

std::vector<int> merge(const std::vector<int>& l, const std::vector<int>& r) {
  std::vector<int> result;
  size_t i = 0, j = 0;
  while (i < l.size() && j < r.size()) {
    result.push_back(l[i] < r[j] ? l[i++] : r[j++]);
  }
  while (i < l.size()) {
    result.push_back(l[i++]);
  }
  while (j < r.size()) {
    result.push_back(r[j++]);
  }
  return result;
}

std::vector<int> merge_sort_helper(const std::vector<int>& vec, int begin,
                                   int end) {
  if (begin >= end) {
    return {vec[begin]};
  }
  int mid = begin + (end - begin) / 2;
  auto l = merge_sort_helper(vec, begin, mid);    // 排序左边
  auto r = merge_sort_helper(vec, mid + 1, end);  // 排序右边
  return merge(l, r);                             // 合并两个有序序列
}

// 归并排序
// 基于分治思想，把问题拆分成子问题，汇总子问题的结果即可
// 把问题转化以下：假设有两个有序数组，怎么合并成一个呢？
std::vector<int> merge_sort(const std::vector<int>& vec) {
  return merge_sort_helper(vec, 0, vec.size() - 1);
}

void merge_sort_non_recursion_helper(std::vector<int>& vec, int begin_1,
                                     int end_1, int begin_2, int end_2) {
  std::vector<int> result;
  // result.reserve(end_2 - begin_1 + 1);
  int offset = begin_1;

  while (begin_1 <= end_1 && begin_2 <= end_2) {
    result.push_back((vec[begin_1] < vec[begin_2]) ? vec[begin_1++]
                                                   : vec[begin_2++]);
  }

  while (begin_1 <= end_1) {
    result.push_back(vec[begin_1++]);
  }

  while (begin_2 <= end_2) {
    result.push_back(vec[begin_2++]);
  }

  std::copy(result.begin(), result.end(), vec.begin() + offset);
}

// 非递归实现
// 关键在于如何划分子序列
// NOTE: 边界条件要注意
// [0 1 2 3 4]
//
// [0|1] [2|3] [4]   step = 1
// [0,1|2,3] [4]     step = 2
// [0,1,2,3|4]       step = 4
void merge_sort_non_recursion(std::vector<int>& vec) {
  int n = vec.size();
  for (int step = 1; step < n; step *= 2) {
    for (int i = 0; i < n; i += 2 * step) {
      int begin_1 = i;
      int end_1 = std::min(begin_1 + step - 1, n - 1);
      int begin_2 = std::min(end_1 + 1, n - 1);
      int end_2 = std::min(begin_2 + step - 1, n - 1);
      //std::cout << "[" << begin_1 << "," << end_1 << "|" << begin_2 << ","
      //          << end_2 << "]" << std::endl;
      merge_sort_non_recursion_helper(vec, begin_1, end_1, begin_2, end_2);
    }
  }
}

