/*************************************************************************
    > File Name: 26.cpp
    > Author:
    > Mail:
    > Created Time: 2017年12月28日 星期四 11时07分56秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// unique 会完成去重，然后返回新范围的结尾迭代器。
// 最后用distance求一下元素个数即可

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        return std::distance(nums.begin(), std::unique(nums.begin(), nums.end()));
    }
};

//class Solution2 {
//public:
//    int removeDuplicates(int A[], int n) {
//        return removeDuplicates(A, A + n, A) - A;
//    }
//    template<typename InIt, typename OutIt>
//    OutIt removeDuplicates(InIt first, InIt last, OutIt output) {
//        while (first != last) {
//            *output++ = *first;
//            first = upper_bound(first, last, *first);
//        }
//        return output;
//    }
//};




// 把此数组空间，想象成两个空间，一个输入，一个输出。两个空间没有冲突
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        //vector<int>::iterator first, last, output;

        auto first = output = nums.begin(); // output代表输出迭代器，每次前进1
        auto last  = nums.end();

        while(first != last)
        {
            *output++ = *first; // 写入输出空间
            first = std::upper_bound(first, last, *first); // 找到下一个相异元素
        }
        return std::distance(nums.begin(), output); // 返回新大小
    }
};
