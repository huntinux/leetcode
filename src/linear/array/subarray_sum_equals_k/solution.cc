#include "solution.h"

// 分析
// 滑动窗口法
// 窗口内元素和sum不足k则扩大范围右边界向右，sum正好为k时，结果加1
// sum大于k时缩小范围，左边界向右
//
// 注意：可能有负数元素，这个解法是错误的
#if 0
int Solution::subarraySum(vector<int>& nums, int k) {
  if (nums.size() == 0) return 0;
  int result = 0, left = 0, right = left + 1, sum = nums[0];
  while (left < right && right <= nums.size()) {
    if (sum == k) {
      result++;
      sum -= nums[left++];
      if (left == right) {
        if (right < nums.size()) {
          sum += nums[++right];
        }
      }
    } else if (sum < k) {
      if (right < nums.size()) {
        sum += nums[right++];
      } else {
        break;
      }
    } else {
      sum -= nums[left++];
      if (left == right) {
        if (right < nums.size()) {
          sum += nums[++right];
        }
      }
    }
  }
  return result;
}
#endif

// 正确做法1
// 暴力搜索
// 时间复杂度O(N*N) 空间复杂度O(1)
int subarraySum2(vector<int>& nums, int k) {
  int count = 0;
  for (int start = 0; start < nums.size(); ++start) {
    int sum = 0;
    for (int end = start; end >= 0; --end) {
      sum += nums[end];
      if (sum == k) {
        count++;
      }
    }
  }
  return count;
}

// 正确做法2
// 前缀和+hashmap
// 时间复杂度O(n) 空间复杂度O(n)
// ref :
// https://leetcode-cn.com/problems/subarray-sum-equals-k/solution/he-wei-kde-zi-shu-zu-by-leetcode-solution/
int Solution::subarraySum(vector<int>& nums, int k) {
  unordered_map<int, int> mp;
  mp[0] = 1;
  int count = 0, pre = 0;
  for (auto& x : nums) {
    pre += x;
    if (mp.find(pre - k) != mp.end()) {
      count += mp[pre - k];
    }
    mp[pre]++;
  }
  return count;
}
