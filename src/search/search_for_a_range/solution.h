#pragma once

#include <vector>

using std::vector;

// 34. Find First and Last Position of Element in Sorted Array
class Solution {
 public:
  // Input: nums = [5,7,7,8,8,10], target = 8
  // Output: [3,4]
  vector<int> SearchRange(vector<int>& nums, int target);

  int lower_bound(const vector<int>& nums, int target);
  int upper_bound(const vector<int>& nums, int target);

};
