#pragma once

#include <vector>

using std::vector;

/*
Given an array of positive integers nums and a positive integer target, return
the minimal length of a contiguous subarray [numsl, numsl+1, ..., numsr-1,
numsr] of which the sum is greater than or equal to target. If there is no such
subarray, return 0 instead.

Follow up: If you have figured out the O(n) solution, try coding another
solution of which the time complexity is O(n log(n)).
*/

class Solution {
 public:
  // Input: target = 7, nums = [2,3,1,2,4,3]
  // Output: 2
  // Explanation: The subarray [4,3] has the minimal length under the problem
  // constraint.
  int minSubArrayLen(int target, vector<int>& nums);
};

