#include "solution.h"

// 非常经典的一道题目
// 生成过程看成一颗树，结合树的深度优先遍历+回溯实现
// 其中depth、used、path是中间的状态变量
void Solution::dfs(vector<int>& nums, int depth, vector<bool>& used,
                   vector<int>& path, vector<vector<int>>& res) {
  // if (path.size() == nums.size()) {
  if (depth == nums.size()) {
    // 递归终止条件，到达最大深度，说明生成了一个合法的结果
    res.push_back(path);
    return;
  }

  for (int i = 0; i < nums.size(); ++i) {
    // 每次找到还没使用过的元素, 从前往后扫描, 因此前面用过的后面不会再用
    if (used[i]) {
      continue;
    }
    used[i] = true;
    path.push_back(nums[i]);

    // 深度优先遍历
    dfs(nums, depth + 1, used, path, res);

    // 状态变量回溯
    path.pop_back();
    used[i] = false;
  }
}

vector<vector<int>> Solution::permute(vector<int>& nums) {
  vector<vector<int>> res;
  if (nums.size() == 0) return res;
  vector<bool> used(nums.size(), false);
  vector<int> path;
  dfs(nums, 0 /*depth*/, used, path, res);
  return res;
}
