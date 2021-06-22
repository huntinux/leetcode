#include "solution.h"

// 分析
//
// 解法1：
//  暴力解法，两层循环，时间复杂度O(n^2)
// 
// 解法2:
//  分治，联想归并排序
//  ref: https://leetcode-cn.com/problems/shu-zu-zhong-de-ni-xu-dui-lcof/solution/jian-zhi-offer-51-shu-zu-zhong-de-ni-xu-pvn2h/
int Solution::ReversePairs(vector<int>& nums) {
  if (nums.size() <= 1) return 0;
  ReverseHelper(nums, 0, nums.size() - 1);
  return reverse_pair_count_;
}

void Solution::ReverseHelper(vector<int>& nums, int start, int end) {
  if (start >= end) return ;
  int mid = start + (end - start) / 2;
  ReverseHelper(nums, start, mid);
  ReverseHelper(nums, mid + 1, end);
  ReverseHelperImpl(nums, start, mid, end);
}

void Solution::ReverseHelperImpl(vector<int>& nums, int start, int mid, int end) {
  int i = start, j = mid + 1;
  int n = end - start + 1;
  vector<int> sorted;
  int m = 0;
  sorted.resize(n);

  while (i <= mid && j <= end) {
    if (nums[i] > nums[j]) {
    //if (nums[i] > (2 * nums[j])) {
      sorted[m++] = nums[j++];
      reverse_pair_count_ += (mid - i + 1); // 更新逆序数量
    } else {
      sorted[m++] = nums[i++];
    }
  }

  while (i <= mid) {
    sorted[m++] = nums[i++];
  }

  while (j <= end) {
    sorted[m++] = nums[j++];
  }

  for (size_t i = 0; i < sorted.size(); ++i) {
    nums[start + i] = sorted[i];
  }
}
