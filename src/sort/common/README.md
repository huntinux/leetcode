> https://en.wikipedia.org/wiki/Sorting_algorithm

要数量各种排序算法的原理、实现方法、时间复杂度、空间复杂度、稳定性

STL对应的工具是哪些

```cpp
1. 堆排序
std::priority_queue<int> max_heap; // 大根堆
std::priority_queue<int, vector<int>, greater<int>> min_heap; // 小根堆
添加元素：时间复杂度 O(logn)

2. 结合二分查找，实现插入排序
二分查找+插入排序
vector<int> store; // resize-able container
store.insert(lower_bound(store.begin(), store.end(), num), num);
时间复杂度：O(n) + O(logn) ≈ O(n).
二分搜索需要花费 O(logn) 时间才能找到正确的插入位置。
插入可能需要花费 O(n) 的时间，因为必须在容器中移动元素为新元素腾出空间。

3. 快速排序
std::sort(store.begin(), store.end()) // 快排, 不稳定, 时间复杂度nlog(n)

```
