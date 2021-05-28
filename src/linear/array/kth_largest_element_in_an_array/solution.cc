#include "solution.h"

#include <queue>
#include <unordered_set>

// 方法1
// 先排序，然后返回第k个元素
//
// 方法2
// 只需要找到第k大的树，其实没有必要全部排序
// 联想快速排序，它每一趟能够确定一个元素的位置n
// 如果n == k，那么恭喜你找到答案了
// 如果n < k, 说明答案在n的右边，继续在n的右边重复上面的过程
// 否则在n的左边重复上面的过程即可
//
// 第一种方法太简单，这里实现第二种方法
//
// 以nums[low]为pivot, 是得大于pivot的元素位于pivot左边，小于pivot位于pivot右边
// 返回值为最终pivot的位置
//
// 注意，这种方法修改了原始数组内容
int partition(vector<int>& nums, int low, int high) {
  int pivot = low;
  int pivot_value = nums[pivot];
  while (low < high) { // 注意这里不需要加=条件, low = high时，即为pivot的最终位置
    while (low < high && nums[high] < pivot_value) --high;
    if (low < high) {
      nums[low] = nums[high];
      ++low;
    }
    while (low < high && nums[low] > pivot_value) ++low;
    if (low < high) {
      nums[high] = nums[low];
      --high;
    }
  }
  pivot = low;
  nums[pivot] = pivot_value;
  return pivot;
}

int Solution::FindKthLargest(vector<int>& nums, int k) {
  int low = 0, high = nums.size() - 1;
  while (low < high) { // 注意这里，不需要加=条件
    int n = partition(nums, low, high);
    if ((n + 1) == k) {
      break;
    } else if ((n + 1) > k) {
      high = n - 1;
    } else {
      low = n + 1;
    }
  }
  return nums[k - 1];
}

// 方法3：可以借助小根堆
//
// c++里面可以使用priority_queue/multiset当作堆
//
// priority_queue默认用less<int>, 实现了大根堆，top()为largest
// 所以想用小根堆，可以使用greater<int>
//
// 注意：这种方法没有改变原始数组内容
// 此外这个方法比方法1要快，原因分析
//  堆排序最好、最坏时间复杂度都是O(nlog(n))
//  而快速排序最好为O(nlog(n)), 最坏退化为O(n^2)
//
// int Solution::FindKthLargest(vector<int>& nums, int k) {
//  std::priority_queue<int, vector<int>, std::greater<int>> pq;
//  for (auto n : nums) {
//    pq.push(n);
//    if (pq.size() > k) {
//      pq.pop();
//    }
//  }
//  return pq.top();
//}

// 其他方法: 使用STL nth_element partial_sort
// int findKthLargest(vector<int>& nums, int k) {
//  nth_element(nums.begin(), nums.begin() + k - 1, nums.end(), greater<int>());
//  return nums[k - 1];
//}
// int findKthLargest(vector<int>& nums, int k) {
//  partial_sort(nums.begin(), nums.begin() + k, nums.end(), greater<int>());
//  return nums[k - 1];
//}
