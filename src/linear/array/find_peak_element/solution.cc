#include "solution.h"

// 分析
//  如果某个元素比它左边和右边元素都大时，它就是峰值
//  题目要求时间复杂度：O(logN), 考虑使用二分查找
//
// 解法
//  注意已知条件，数组左右时负无穷
//  取范围内[0, nums.size() - 1]的中间元素mid
//    若nums[mid] < nums[mid+1] , mid在一个上升序列中，因为最右边为负无穷， i
//    因此答案在右边, 缩小查找范围为 [mid+1, high];
//    否则, mid在一个递减序列中，因为最左边为负无穷，所以答案在左边
//    最后low==high为答案
//
//  example
//    nums: [1, 2, 3]
//    - low = 0, high = 2
//    - mid = 1, nums[mid] < nums[mid+1]
//    - low = mid + 1 = 2 high = 2
//    - return low = 2;
//
//  example
//    nums{1, 2, 1, 3, 5, 6, 4};
//    - low = 0, high = 6; 
//    - mid = 3, nums[3] < nums[4]
//    - low = mid + 1 = 4, high = 6
//    - mid = 5, nums[5] > nums[6]
//    - high = mid = 5, low = 4
//    - mid = 4, nums[4] < nums[5]
//    - low = mid + 1 = 5, high = 5
//    - return low = 5;
int Solution::findPeakElement(vector<int>& nums) {
  int low = 0, high = nums.size() - 1;
  while (low < high) {
    int mid = low + (high - low) / 2;
    if (nums[mid] < nums[mid + 1]) {
      low = mid + 1;
    } else {
      high = mid;
    }
  }
  return low;
}
