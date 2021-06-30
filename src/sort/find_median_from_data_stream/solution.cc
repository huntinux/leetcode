#include "solution.h"

// ref:
// https://leetcode-cn.com/problems/find-median-from-data-stream/solution/shu-ju-liu-de-zhong-wei-shu-by-leetcode/

// 解法1
//  使用vector存储元素，每次添加后进行排序，返回中位数即可
//  std::sort() 时间复杂度为nlog(n)
// 解法2
//  添加元素时，利用二分查找，找到插入位置。类似插入排序
//  时间复杂度为 O(logn)(二分查找) + O(n)(移动数组元素) = O(n)
// 解法3
//  利用堆排序，一个大根堆，一个小根堆，通过调整，让两个堆中元素个数差为1，中位数
//  可以通过两个堆的堆顶获得
//
// 下面主要实现解法2和解法3

// 解法2
/*
void MedianFinder::addNum(int num) {
  // std::lower_bound 返回第一个不大于num的迭代器，
  // 注意lower_bound可能会返回end迭代器
  // vector::insert是在某个迭代器之前插入, 因此在end之前插入也是合法的
  nums_.insert(std::lower_bound(nums_.begin(), nums_.end(), num), num);
}

double MedianFinder::findMedian() {
  if (nums_.size() & 0x1) {
    return nums_[nums_.size() / 2];
  } else {
    return (nums_[nums_.size() / 2] + nums_[nums_.size() / 2 - 1]) / 2.0;
  }
}
*/

// 解法3 借助堆排序
//
// 创建一个大根堆和一个小根堆，大根堆存放集合中较小的元素集合，因为我们记它为
// small，小根堆存放集合中较大的元素，记它为big。
// 只要保证small和big的元素个数差不超过1，就可以根据small.top和big.top 
// 获得中位数的值
//
// 每次num先加入大根堆(记为small， 因为它存放的是整个集合较小元素集合)，
// 加入后经过堆排序，得到最大元素即small.top(), 把它移动到小根堆big
// 然后为了平衡两个堆的元素数量，可能需要调整，触发条件为
// 两个堆的数量差大于1时，将将小根堆big.top移动都大根堆small即可
//
// 时间复杂度： O(logn)
void MedianFinder::addNum(int num) {
  small_.push(num);
  big_.push(small_.top());
  small_.pop();
  if (big_.size() - small_.size() > 1) {
    small_.push(big_.top());
    big_.pop();
  }
}

double MedianFinder::findMedian() {
  if (big_.size() > small_.size()) {
    return big_.top();
  } else {
    return (big_.top() + small_.top()) * 0.5;
  }
}
