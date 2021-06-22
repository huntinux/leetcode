#include "solution.h"

// Input: nums = [10,9,2,5,3,7,101,18]
// Explanation: The longest increasing subsequence is [2,3,7,101], therefore
// Output: 4
//
// 分析
// 子序列不一定是连续的
// 借助动态规划
// 比如 f[i] 表示 以arr[i]结尾的LIS值
// 结果就是f[i]中的最大值
//
// 递推公式
// 初始值f[i] = 1 其中 1<=i<=n
//  f[i] = max(f[j] + 1) if(arr[j] < arr[i]); (其中0<=j<i)
//
// 时间复杂度O(n^2)
// 空间复杂度O(n)
//
int Solution::LengthOfLIS(vector<int>& nums) {
  if (nums.size() == 0) return 0;
  vector<int> lis(nums.size());
  int max_lis = 1;
  lis[0] = 1;
  for (int i = 1; i < nums.size(); ++i) {
    lis[i] = 1;
    for (int j = 0; j < i; ++j) {
      if (nums[j] < nums[i] && (lis[i] < lis[j] + 1)) {
        lis[i] = lis[j] + 1;
        if (lis[i] > max_lis) {
          max_lis = lis[i];
        }
      }
    }
  }
  return max_lis;
}

// from leetcode
//
// 说明
// res[i] keeps track of the smallest tail of subsequences with length i + 1. We
// iterate through nums, and it points to the first element in res that >=
// nums[i]. If we find this element, we can update it with nums[i], since
// nums[i] is greater than all previous elements, and may be smaller than *it.
int lengthOfLIS(vector<int>& nums) {
  vector<int> res;  // 存放有序结果，这样可以通过二分查找加速
  for (int i = 0; i < nums.size(); i++) {
    auto it = std::lower_bound(res.begin(), res.end(), nums[i]);
    // if not find then push_back, if find, then replace. *it = nums[i] means
    // replace the tail item of res to nums[i], because nums[i] is less than it.
    if (it == res.end())
      res.push_back(nums[i]);
    else
      *it = nums[i];
  }
  return res.size();
}

// 解释
// Indeed, geeksforgeeks provides a very detailed explanation, but maybe a short
// summary would help.
//
// The algo is O(nlogn) because lower_bound() is logarithmic on a sorted input.
// We keep our vector res sorted, so the search in dp is logarithmic. Res is
// composed to be: sorted having a length of the longest found increasing
// sub-sequence So it doesn't contain that subsequence. Only it's length is
// valid. So what algo is doing? For each number we have 2 options: if it's the
// highest found value, we push it back, since a high value obviously makes our
// increasing sequence longer if it's not the highest found value, then it could
// be a nice start (or continuation) of a shorter sequence. And we keep that
// sequence in place. Merging all found and possible sequences into one dp
//
// [1,2,7,8,3,4,5,9,0]
// 1 -> [1]
// 2 -> [1,2]
// 7 -> [1,2,7]
// 8 -> [1,2,7,8]
// 3 -> [1,2,3,8]  // we replaced 7 with 3, since for the longest sequence we
// need only the last number and 1,2,3 is our new shorter sequence 
// 4 -> [1,2,3,4] // we replaced 8 with 4, since the max len is the same but 4 has
// more chances for longer sequence 
// 5 -> [1,2,3,4,5] 
// 9 -> [1,2,3,4,5,9] 
// 0 -> [0,2,3,4,5,9] // we replaced 1 with 0, so that it can become a new sequence
// So in the end our res contains [0,2,3,4,5,9] which is not a found sequence,
// but it has the length of the valid answer = 6.
//
// ref: https://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/

