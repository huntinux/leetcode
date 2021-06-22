#include "solution.h"

// 分析
//  解题思路：
//  相信大家读了题目会发现与逆序对（剑指Offer51题）很相似，那么做过那道题后，
//  我们就可以知道大概率可以采用归并排序的思路来解决这个问题。
//  但是与逆序对不同的是，在这道题的归并过程中没有办法一边计算翻转对数目，
//  一边就完成了数组的排序。但这个无伤大雅，我们主要是想通过类似的思路来更快计算翻转对数目，即：
//
//  设nums[i]是左半边的有序数组，nums[j]是右半边的有序数组，均为从大到小有序。
//  若找到满足条件的nums[i]和nums[j]之后，那么根据数组有序的条件，可以直接知道
//  nums[j]右边所有的数字与nums[i]都可以满足翻转对关系，即可直接计算(通过r-j+1计算)。
//  因为没法在此过程中就完成数组排序，那么我们直接采用sort函数完成即可。
//
// ref :
// https://leetcode-cn.com/problems/reverse-pairs/solution/jian-zhi-offer51ni-xu-dui-xiang-tong-tao-ydmx/

#define OPTIMIZE

int Solution::ReversePairs(vector<int>& nums) {
  if (nums.size() <= 1) return 0;
#ifndef OPTIMIZE
  ReverseHelper(nums, 0, nums.size() - 1);
#else
  vector<int> aux(nums.size(), 0);
  ReverseHelper(nums, 0, nums.size() - 1, aux);
#endif
  return reverse_pair_count_;
}

void Solution::ReverseHelper(vector<int>& nums, int start, int end) {
  if (start >= end) return;
  int mid = start + (end - start) / 2;
  ReverseHelper(nums, start, mid);
  ReverseHelper(nums, mid + 1, end);

  // 左右变成有序序列后, 再根据条件扫描逆序
  // 充分利用排序结果，避免不必要的比较
  int i = start, j = mid + 1;
  while (i <= mid && j <= end) {
    if (nums[i] > (2L * nums[j])) {  // 注意溢出问题
      reverse_pair_count_ += (mid - i + 1);
      ++j;
    } else {
      ++i;
    }
  }

  // 将左右进行合并
  ReverseHelperImpl(nums, start, mid, end);
}

void Solution::ReverseHelperImpl(vector<int>& nums, int start, int mid,
                                 int end) {
  int i = start, j = mid + 1;
  int n = end - start + 1;
  vector<int> sorted;
  int m = 0;
  sorted.resize(n);

  while (i <= mid && j <= end) {
    if (nums[i] > nums[j]) {
      sorted[m++] = nums[j++];
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

void Solution::ReverseHelper(vector<int>& nums, int start, int end,
                             vector<int>& aux) {
  if (start >= end) return;
  int mid = start + (end - start) / 2;
  ReverseHelper(nums, start, mid, aux);
  ReverseHelper(nums, mid + 1, end, aux);

  // 左右变成有序序列后, 再根据条件扫描逆序
  // 充分利用排序结果，避免不必要的比较
  int i = start, j = mid + 1;
  while (i <= mid && j <= end) {
    if (nums[i] > (2L * nums[j])) {  // 注意溢出问题
      reverse_pair_count_ += (mid - i + 1);
      ++j;
    } else {
      ++i;
    }
  }

  // 将左右进行合并
  ReverseHelperImpl(nums, start, mid, end, aux);
}

void Solution::ReverseHelperImpl(vector<int>& nums, int start, int mid, int end,
                                 vector<int>& aux) {
  int i = start, j = mid + 1;
  vector<int>& sorted = aux;
  int m = start;

  while (i <= mid && j <= end) {
    if (nums[i] > nums[j]) {
      sorted[m++] = nums[j++];
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

  for (int i = start; i <= end; ++i) {
    nums[i] = sorted[i];
  }
}
