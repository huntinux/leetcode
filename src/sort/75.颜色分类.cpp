/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

// @lc code=start
class Solution {
public:
    // 联想 3ways-quicksort
    // 取 1 为pivot即可
    // start: 23:13
    void sortColors(vector<int>& nums) {
       int pivot = 1;
       // 保证最左边元素为pivot
       for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] == 1) {
            std::swap(nums[0], nums[i]);
            break;
        }
       }

       // 同 3way-quicksort 的一次 partition
       int lt = 0, gt = nums.size() - 1; 
       int i = lt + 1;
       while (i <= gt) {
            if (nums[i] < pivot) {
                std::swap(nums[i++], nums[lt++]);
            } else if (nums[i] > pivot) {
                std::swap(nums[i], nums[gt--]);
            } else {
                i++;
            }
       }
    }
};
// @lc code=end

