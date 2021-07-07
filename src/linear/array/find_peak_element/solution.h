#pragma once

#include <vector>

using std::vector;

/*
A peak element is an element that is strictly greater than its neighbors.

    Given an integer array nums,
    find a peak element,
    and return its index.If the array contains multiple peaks,
    return the index to any of the peaks.
*/

class Solution {
 public:
  // Input: nums = [1,2,3,1]
  // Output: 2
  // Explanation: 3 is a peak element and your function should return the index number 2.
  int findPeakElement(vector<int>& nums);
};
