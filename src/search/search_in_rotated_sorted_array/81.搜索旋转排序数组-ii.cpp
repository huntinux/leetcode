/*
 * @lc app=leetcode.cn id=81 lang=cpp
 *
 * [81] 搜索旋转排序数组 II
 */

// @lc code=start
class Solution {
public:
    // 与 33 的区别在于允许存在重复元素，那么 left <= mid --> left is sorted 就不成立了，比如
    // 1 3 1 1 1 1
    // 那么就把 left <= mid 再拆分一下
    // left < mid --> left is sorted
    // left == mid --> ignore duplicated element ： left ++
    bool search(vector<int>& nums, int target) {
        if (nums.size() == 0) return false;
        int low = 0, high = nums.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) return true;
            if (nums[low] < nums[mid]) {
                if (nums[low] <= target && target < nums[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else if (nums[low] != nums[mid]) {
                if (nums[mid] < target && target <= nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            } else {
                low++;
            }
        }
        return false;
    }
};
// @lc code=end

