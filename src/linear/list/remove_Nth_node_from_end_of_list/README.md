lru cache的实现 
map + list
map提供o(1)的查找能力
list可以方便的移动元素位置

扩展
线程安全的lrucache：使用mutex
当mutex成为热点，可以考虑分段加锁
或者无锁实现
