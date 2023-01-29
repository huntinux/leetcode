#include <unordered_set>

/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

// @lc code=start
class Solution {
public:
    // 借助hashmap以O(1)的时间复杂度快速判读一个数字是否存在
    int longestConsecutive(vector<int>& nums) {
        int max = 0;
        std::unordered_map<int, bool> dict;
        for (auto n : nums) {
            dict[n] = false;
        }
        for (int i = 0; i < nums.size(); ++i) {
            int l = 1;
            int n = nums[i];
            if (!dict[n]) {
                for (int left = n - 1; dict.find(left) != dict.end(); --left) {
                    dict[left] = true;
                    l++;
                }
                for (int right = n + 1; dict.find(right) != dict.end(); ++right) {
                    dict[right] = true;
                    l++;
                }
            }
            if (l > max) max = l;
        }
        return max;
    }
};
// @lc code=end

