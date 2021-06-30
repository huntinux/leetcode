#pragma once

#include <vector>
#include <queue>

class MedianFinder {
 public:
  /** initialize your data structure here. */
  MedianFinder() {}
  void addNum(int num);
  double findMedian();
  const std::vector<int>& getNums() const { return nums_; }

 private:
  // 解法2
  std::vector<int> nums_;

  // 解法3
  std::priority_queue<int> small_; // 大根堆，存储较小的那些元素
  std::priority_queue<int, std::vector<int>, std::greater<int>> big_; // 小根堆，存储较大的那些元素
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
