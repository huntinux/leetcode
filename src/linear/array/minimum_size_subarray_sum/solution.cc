#include "solution.h"

//
// 分析
// 给定一个包含正整数的无序数组和一个target，找到大于等于target的子数组的最小长度
//
// 例子
// Input: target = 7, nums = [2,3,1,2,4,3]
// Output: 2
// Explanation: The subarray [4,3] has the minimal length under the problem
// constraint.
//
// 解法1：暴力搜索
// 首先找到所有和大于等于target的子序列
// [2,3,1,2]
// [2,3,1,2,4]
// [2,3,1,2,4,3]
// [3,1,2,4]
// [3,1,2,4,3]
// [1,2,4]
// [1,2,4,3]
// [2,4,3]
// [4,3]
// 最后返回最短长度即为2
// 时间复杂度为O(n*n)
//
// 解法2: 滑动窗口
// 初始状态下，窗口大小为0(left=right=0), 窗口内元素和s也为0
// 扫描数组
//  如果 s < target， 则将nums[i]加入此窗口 right += 1 s += nums[i]
//  否则说明窗口内的元素满足条件，但是可能长度不是最短的，
//  没关系，我们先保持它的长度minlen = right - left。
//  同时 s -= nums[left], left += 1
//
// example
// - left = right = 0, s = 0
// - i = 0, nums[0] = 2, s = 0 < target = 7
//  - right += 1 = 1, s += nums[0] = 2
// - i = 1, nums[1] = 3, s = 2 < target = 7
//  - right += 1 = 2, s += nums[1] = 5
// - i = 2, nums[2] = 1, s = 5 < target = 7
//  - right += 1 = 3, s += nums[2] = 6
// - i = 3, nums[3] = 2, s = 6 < target = 7
//  - right += 1 = 4, s += nums[3] = 8
// - i = 4, nums[4] = 4, s = 8 > target = 7, minlen = right - left = 4-0 = 4
//  - s -= nums[left] s-=nums[0] = 8 - 2 = 6
//  - left += 1 = 1
// - i = 5, nums[5] = 3, s = 6 < target = 7
//  - right += 1 = 5, s += nums[5] = 6 + 3
//
//  最后不断缩小范围，最后返回最短长度即为
// - s = 9 > target = 7
//  - s -= nums[left--] 知道不满足 >= target
//
// 整理下思路
//  就把当前元素加入到窗口中
//  如果窗口内元素和 >= target 弹出左侧元素，直到 < target
//  过程中不断更新minlen
int Solution::minSubArrayLen(int target, vector<int>& nums) {
  // 注意，minlen的初始值设置为一个特殊值，方便后面判断是否有解
  int left = 0, right = 0, minlen = nums.size() + 1, sum = 0;
  for (int i = 0; i < nums.size(); ++i) {
    sum += nums[right++];
    if (sum >= target) {
      while ((sum - nums[left]) >= target) {
        sum -= nums[left++];
      }
      int len = right - left;
      if (len < minlen) {
        minlen = len;
      }
    }
  }
  return (minlen == nums.size() + 1) ? 0 : minlen;
}

// 解法3
// 前缀和 + 二分查找
// 因为这道题保证了数组中每个元素都为正，所以前缀和一定是递增的，
// 这一点保证了二分的正确性。如果题目没有说明数组中每个元素都为正，
// 这里就不能使用二分来查找这个位置了。
// ref: https://leetcode-cn.com/problems/minimum-size-subarray-sum/solution/chang-du-zui-xiao-de-zi-shu-zu-by-leetcode-solutio/
