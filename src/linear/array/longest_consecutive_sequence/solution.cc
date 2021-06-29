#include "solution.h"

#include <unordered_map>

// Input: nums = [100,4,200,1,3,2]
// Output: 4
// Explanation: The longest consecutive elements sequence is [1, 2, 3, 4].
// Therefore its length is 4.
//
// 分析
//  输入数组是无序的，可以先排序，然后再统计，时间复杂度O(nlogn), 但是题目要求
//  O(n)。考虑借助hashmap提供快速查找能力，对每个元素，左右扩展求解
int Solution::longestConsecutive(vector<int>& nums) {
  std::unordered_map<int, bool> used;
  for (auto n : nums) {
    used[n] = false;
  }
  int result = 0;
  for (auto n : nums) {
    if (used[n]) continue;
    int length = 1;
    // 尝试从左右分别扩展
    for (int i = n - 1; used.find(i) != used.end(); --i) {
      used[i] = true;
      length++;
    }
    for (int i = n + 1; used.find(i) != used.end(); ++i) {
      used[i] = true;
      length++;
    }
    if (length > result) result = length;
  }
  return result;
}
