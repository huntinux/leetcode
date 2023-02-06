/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
public:
    // start: 22:19
    // end: 22:36
    // 总结：在标准二分查找基础上实现
    // 相等的情况在进行分类讨论
    int lower_bound(const vector<int>& nums, int target) {
        int l = 0, h = nums.size() - 1;
        while (l <= h) {
            int m = l + (h - l) / 2;
            if (target > nums[m]) {
                l = m + 1;
            } else if (target < nums[m]) {
                h = m - 1;
            } else {
                // 如果m为第一个元素了，或者m前面的元素不等于target，则返回m
                // 否则缩减范围为 [l, m-1]
                if (m == 0 || nums[m - 1] != target) return m;
                else h = m - 1;
            }
        }
        return -1;
    }
    int upper_bound(const vector<int>& nums, int target) {
        int l = 0, h = nums.size() - 1;
        while (l <= h) {
            int m = l + (h - l) / 2;
            if (target > nums[m]) {
                l = m + 1;
            } else if (target < nums[m]) {
                h = m - 1;
            } else {
                // 如果m为最后一个元素，或者m后面的元素不等于target，则返回m
                // 否则缩减范围为 [m+1, h]
                if ((m == nums.size() - 1) || 
                    nums[m + 1] != target) {
                    return m;
                } else {
                    l = m + 1;
                }
            }
        }
        return -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        return {lower_bound(nums, target), upper_bound(nums, target)};
    }
};
// @lc code=end

