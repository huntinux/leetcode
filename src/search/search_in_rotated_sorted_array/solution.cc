#include "solution.h"

// 分析，排序好的数组经过rotate后也是分段有序的，考虑二分查找的思路解决
int Solution::search(vector<int>& nums, int target) {
  if (nums.size() == 0) return -1;

  int low = 0, high = nums.size() - 1;
  while (low <= high) {
    int mid = low + (high - low) / 2; // 注意(high + low) 可能会溢出
    if (nums[mid] == target) {
      return mid;
    }
    if (nums[low] <= nums[mid]) { // 左侧为有序序列
      if (target < nums[mid] && target >= nums[low]) { // 在左侧有序序列中间
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    } else { // 右侧为有序序列
      if (target > nums[mid] && target <= nums[high]) { // 在右侧有序序列中间
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
  }
  return -1;
}
