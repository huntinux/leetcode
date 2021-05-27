#pragma once

#include <iostream>
#include <list>
#include <unordered_map>

class LruCache {
 public:
  LruCache(int capacity) : capacity_(capacity) {}

  int get(int key) {
    auto it = map_.find(key);
    if (it != map_.end()) {
      auto it_list = it->second;
      list_.splice(list_.begin(), list_, it_list);
      return it_list->second;
    }
    return -1;
  }

  void put(int key, int value) {
    auto it = map_.find(key);
    // 没找到，新建元素放到list头，map[key] = list中的位置
    if (it == map_.end()) {
      std::cout << "add key: " << key << "" << value << std::endl;
      list_.push_front(std::make_pair(key, value));
      map_[key] = list_.begin();
    } else {  // 找到了，更新值，位置换到list头部
      auto it_list = it->second;
      it_list->second = value;
      list_.splice(list_.begin(), list_, it_list);
      std::cout << "modify key: " << key << " value: " << value << std::endl;
    }
    if (size() > capacity_) {
      auto it_list = std::prev(list_.end());
      std::cout << "remove key: " << it_list->first
                << " value: " << it_list->second << std::endl;
      map_.erase(it_list->first);
      list_.pop_back();
    }
  }
  size_t size() const { return list_.size(); }

 private:
  size_t capacity_;
  std::list<std::pair<int, int>>
      list_;  // 需要map通过list的iterator反向获取key的信息，所以list存储了key和value
  std::unordered_map<int, std::list<std::pair<int, int>>::iterator> map_;
};

/**
 *Your LRUCache object will be instantiated and called as such:
 *LRUCache* obj = new LRUCache(capacity);
 *int param_1 = obj->get(key);
 *obj->put(key,value);
 **/

/*
Design a data structure that follows the constraints of a Least Recently Used
(LRU) cache.

Implement the LRUCache class:

    LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
    int get(int key) Return the value of the key if the key exists, otherwise
return -1. void put(int key, int value) Update the value of the key if the key
exists. Otherwise, add the key-value pair to the cache. If the number of keys
exceeds the capacity from this operation, evict the least recently used key.
    Follow up:
    Could you do get and put in O(1) time complexity?
*/

// from leetcode
class LRUCache {
 public:
  LRUCache(int capacity) : _capacity(capacity) {}

  int get(int key) {
    auto it = cache.find(key);
    if (it == cache.end()) return -1;
    touch(it);
    return it->second.first;
  }

  void set(int key, int value) {
    auto it = cache.find(key);
    if (it != cache.end())
      touch(it);
    else {
      if (cache.size() == _capacity) {
        cache.erase(used.back());
        used.pop_back();
      }
      used.push_front(key);
    }
    cache[key] = {value, used.begin()};
  }

 private:
  typedef std::list<int> LI;
  typedef std::pair<int, LI::iterator> PII;
  typedef std::unordered_map<int, PII> HIPII;

  void touch(HIPII::iterator it) {
    int key = it->first;
    used.erase(it->second.second);
    used.push_front(key);
    it->second.second = used.begin();
  }

  HIPII cache;
  LI used;
  int _capacity;
};
