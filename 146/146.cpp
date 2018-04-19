// 使用双向链表，因为需要高效的任意位置的删除，头部插入
// 使用hash map，因为需要快速定位链表中的节点
class LRUCache {
    typedef int Key;
    typedef int Value;
    typedef list<pair<Key, Value>>::iterator NodeIter;
public:
    LRUCache(int capacity)
		: l(capacity),
		  m(capacity),
		  cap(capacity)
    {

    }

    int get(int key) {
    	auto e = m.find(key);
    	if (e == m.end()) {
    		return -1;
    	} else {
            auto k = e->second->first;
    		auto v = e->second->second;
    		l.erase(e->second);
    		l.push_front(make_pair(k, v));
    		return v;
    	}
    }

    void put(int key, int value) {
        auto e = m.find(key);
    	if (e == m.end()) {
    		if (l.size() == cap) {
    			m.erase(l.back().first);
    			l.pop_back();
    		}
    		l.push_front(make_pair(key, value));
    		m.insert(std::make_pair(key, l.begin()));
    	} else {
            e->second->second = value;
            auto k = e->second->first;
    		auto v = e->second->second;
    		l.erase(e->second);
    		l.push_front(make_pair(k, v));
        }
    }

    void show()
    {
    	std::cout << "Values:" << std::endl;
    	for(auto iter : l) {
    		std::cout << iter.first << ":" << iter.second;
    	}
    	std::cout << std::endl;
    }
private:

    list<pair<Key, Value>> l;
    std::unordered_map<Key, NodeIter> m;
    int cap;
};
