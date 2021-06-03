#include "solution.h"

// 分析
// nums数组已经排序好了，但是里面有重复元素，需要找到target的出现范围
// 联想到标准库里面的lower_bound, upper_bound
// 我们手动实现它们两个就得到答案了
vector<int> Solution::SearchRange(vector<int>& nums, int target) {
  return {lower_bound(nums, target), upper_bound(nums, target)};
}

int Solution::lower_bound(const vector<int>& nums, int target) {
  int n = nums.size();
  if (n == 0) return -1;
  int low = 0, high = n - 1, result = -1;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (nums[mid] >= target) {  // 即使等于，也假设答案在左边
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  if (low < n &&
      nums[low] == target)  // 循环结束再判断下low所在位置是否为target，
                            // 如果是，low记为最左边的, 兼容没有找到的情况
                            // NOTE:
                            // 一开始没有注意检查low的合法性导致下标越界
    result = low;
  return result;
}

int Solution::upper_bound(const vector<int>& nums, int target) {
  if (nums.size() == 0) return -1;
  int low = 0, high = nums.size() - 1, result = -1;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (nums[mid] <= target) {  // 即使等于，也假设答案在右边
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  if (high >= 0 && nums[high] == target) result = high;
  return result;
}

// from leetcode
// 当target不存在时，让lower_bound返回最后一个小于它的数字的下标
//
// vector<int> searchRange(vector<int>& nums, int target) {
//   int idx1 = lower_bound(nums, target);
//   int idx2 = lower_bound(nums, target + 1) - 1;
//   if (idx1 < nums.size() && nums[idx1] == target)
//     return {idx1, idx2};
//   else
//     return {-1, -1};
// }
// 
// int lower_bound(vector<int>& nums, int target) {
//   int l = 0, r = nums.size() - 1;
//   while (l <= r) {
//     int mid = (r - l) / 2 + l;
//     if (nums[mid] < target)
//       l = mid + 1;
//     else
//       r = mid - 1;
//   }
//   return l;
// }
