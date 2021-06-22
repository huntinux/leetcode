#pragma once

/*
Given an integer array nums, return the number of reverse pairs in the array.
A reverse pair is a pair (i, j) where 0 <= i < j < nums.length and nums[i] > 2 *
nums[j].

Input: nums = [1,3,2,3,1]
Output: 2
*/

#include <vector>

using std::vector;

class Solution {
 public:
  int ReversePairs(vector<int>& nums);

 private:
  void ReverseHelper(vector<int>& nums, int start, int end);
  void ReverseHelperImpl(vector<int>& nums, int start, int mid, int end);

  void ReverseHelper(vector<int>& nums, int start, int end, vector<int>& aux);
  void ReverseHelperImpl(vector<int>& nums, int start, int mid, int end,
                         vector<int>& aux);

 private:
  int reverse_pair_count_ = 0;
};
