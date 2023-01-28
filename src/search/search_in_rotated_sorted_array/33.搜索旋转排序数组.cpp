/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
class Solution {
public:
    // start: 16点06分
    // design: 16点13分
    // end: 16点17分
    // AC: 16点27分
    // 总结：边界条件非常容易出错，标记为 E1
    // 
    // example: [4,5,6,7,0,1,2]
    // low mid high
    // 
    // if (mid == target) return mid
    // if (low < mid) //  left is sorted
    //  if left < target < mid
    //      target in left
    //  else
    //      target in right
    // else //  right is sorted
    //  if mid < target < high 
    //      target in right
    //  else
    //      target in left
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (target == nums[mid]) return mid;
            if (nums[low] <= nums[mid]) { // E1：一开始没有写的是 < 忘记加 = 了
                if (nums[low] <= target && target < nums[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {
                if (nums[mid] < target && target <= nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};
// @lc code=end

