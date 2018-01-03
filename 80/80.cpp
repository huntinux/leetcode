/*************************************************************************
	> File Name: 80.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年01月03日 星期三 10时11分48秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

    template<typename InputIterator, typename OutputIterator>
    int helper(InputIterator begin, InputIterator end, OutputIterator out)
    {
        InputIterator cbegin = begin;

        while(begin != end)
        {
            InputIterator loc = upper_bound(begin, end, *begin);
            int dis = distance(begin, loc);

            if(dis == 1)
            {
                *out++ = *begin;
            }
            else
            {
                *out++ = *begin;
                *out++ = *begin;
            }

            begin = loc;
        }
        return distance(cbegin, out);
    }

    int removeDuplicates(vector<int>& nums) {
        return helper(nums.begin(), nums.end(), nums.begin());
    }
};
