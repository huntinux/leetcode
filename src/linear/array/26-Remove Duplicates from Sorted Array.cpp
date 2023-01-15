/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

#include <algorithm>

// @lc code=start
class Solution {
public:

    // ref: https://legacy.cplusplus.com/reference/algorithm/unique/?kw=unique
    template <typename ForwardIterator>
    ForwardIterator Unique(ForwardIterator begin, ForwardIterator end) {
        if (begin == end) return end;
        ForwardIterator it = begin;
        while (++begin != end) {
            if (!(*it == *begin)) {
                *(++it) = *begin;
            }
        }
        return ++it;
    }

    // 自己实现 std::unique
    int removeDuplicates(vector<int>& nums) {
        return std::distance(nums.begin(), Unique(nums.begin(), nums.end()));
    }

    // 使用 STL
    // start: 14点46分
    // end: 14点48分
    int removeDuplicates_v2(vector<int>& nums) {
        return std::distance(nums.begin(), std::unique(nums.begin(), nums.end()));
    }

    // start: 14点42分
    // end: 14点46分
    int removeDuplicates_v1(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int next_write_pos = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[next_write_pos]) {
                nums[++next_write_pos] = nums[i];
            }
        }
        return next_write_pos + 1;
    }
};
// @lc code=end

