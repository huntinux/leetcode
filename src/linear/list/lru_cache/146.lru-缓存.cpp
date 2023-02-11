/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 */

// @lc code=start
//
// start: 21:31
// end: 21:50
// debug: 22:02
// 
// 数据结构：双向链表+hashmap
//         list：支持快速的调整元素位置
//         hashmap：支持快速查找元素位置
//         list<pair<int, int>> list_;
//         unordered_map<int, list<pair<int, int>::iterator>> map_;
class LRUCache2 {
public:
    LRUCache2(int capacity) : capacity_(capacity) { }
    
    int get(int key) {
        auto it = map_.find(key);
        if (it != map_.end()) {
            auto it_in_list = it->second;
            list_.splice(list_.begin(), list_, it_in_list);
            map_[key] = list_.begin();
            return it_in_list->second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        auto it = map_.find(key);
        if (it != map_.end()) {
            auto it_in_list = it->second;
            it_in_list->second = value; // 更新value
            list_.splice(list_.begin(), list_, it_in_list); // 调整位置
            map_[key] = list_.begin(); // 更新迭代器位置
        } else {
            if (size() >= capacity_) {
                const auto& back = list_.back();
                int key_to_be_removed = back.first;
                list_.pop_back();
                map_.erase(key_to_be_removed);
            }
            //list_.insert(list_.begin(), std::make_pair(key, value));
            list_.push_front(std::make_pair(key, value));
            map_[key] = list_.begin();
        }
    }

    int size() const {
        return list_.size();
    }

private:
    std::list<std::pair<int, int>> list_;
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> map_;
    int capacity_;
};

// 23-02-09
// start: 10:00
// end: 10:27
// - list::splice 的用法
// - put 操作如果key存在，忘记更新value了
class LRUCache {
public:
    LRUCache(int capacity) : capacity_(capacity) { }
    
    int get(int key) {
        auto it = map_.find(key);
        if (it == map_.end()) return -1;
        auto list_it = it->second;
        int value = list_it->second;
        list_.splice(list_.begin(), list_, list_it);
        map_[key] = list_.begin();
        return value;
    }
    
    void put(int key, int value) {
        auto it = map_.find(key);
        if (it == map_.end()) {
            if (list_.size() >= capacity_) {
                auto last = std::prev(list_.end());
                int key = last->first;
                map_.erase(key);
                list_.erase(last);
            }
            list_.insert(list_.begin(), std::make_pair(key, value));
            map_[key] = list_.begin();
        } else {
            it->second->second = value;
            list_.splice(list_.begin(), list_, it->second);
            map_[key] = list_.begin();
        }
    }

    int size() const {
        return list_.size();
    }
private:
    using List = std::list<std::pair<int, int>>;
    using ListIterator = List::iterator;

    List list_;
    std::unordered_map<int, ListIterator> map_;
    int capacity_;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

