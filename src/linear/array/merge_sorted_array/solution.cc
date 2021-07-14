#include "solution.h"

// 两个有序数组合并，而且数组1的空间足够大
//
// 可以从后向前合并，避免移动元素
void Solution::merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
  int pos = m + n - 1;
  int i = m - 1, j = n - 1;
  while (i >= 0 && j >= 0) {
    if (nums1[i] > nums2[j]) {
      nums1[pos--] = nums1[i--];
    } else {
      nums1[pos--] = nums2[j--];
    }
  }
  while (j >= 0) {
    nums1[pos--] = nums2[j--];
  }
}
