#include "solution.h"

// 分析
//  一开始想直接接住归并排序做，但是发现如果不先排序下的话，没办法归并,
//  后面就陷入思维陷阱了，想着怎么直接用归并解决。
//
//  后面看来网上的题解，其实可以先排序字再合并。当判断一种方法不可行时，
//  要学会转变思路.
//
//  具体做法；
//  1. 先对intervals排序
//  2. 再按照规则合并
vector<vector<int>> Solution::merge(vector<vector<int>>& intervals) {
  std::sort(intervals.begin(), intervals.end());
  vector<vector<int>> ans;
  for (int i = 0; i < intervals.size();) {
    int t = intervals[i][1];
    int j = i + 1;
    while (j < intervals.size() && intervals[j][0] <= t) {
      t = std::max(t, intervals[j][1]);
      j++;
    }
    ans.push_back({intervals[i][0], t});
    i = j;
  }
  return ans;
}

