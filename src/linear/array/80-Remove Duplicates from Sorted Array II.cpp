/*
 * @lc app=leetcode.cn id=80 lang=cpp
 *
 * [80] 删除有序数组中的重复项 II
 */

// @lc code=start
class Solution {
public:
    // start: 15点08分
    // end: 15点18分
    // 在问题 26 的基础上增加一个计数
    int removeDuplicates(vector<int>& nums) {
        static const int kMaxRepeatedCnt = 2;
        if (nums.size() == 0) return 0;
        int pos = 0, repeated = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[pos]) {
                nums[++pos] = nums[i];
                repeated = 1;
            } else {
                if (repeated < kMaxRepeatedCnt) {
                    nums[++pos] = nums[i];
                    repeated++;
                }
            }
        }
        return pos + 1;
    }
};
// @lc code=end

