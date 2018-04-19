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
            //auto k = e->second->first;
    		auto v = e->second->second;
    		//l.erase(e->second);
    		//l.push_front(make_pair(k, v));
            l.splice(l.begin(), l, e->second); // 使用splice避免节点的删除和创建，直接修改指针，ps：splice函数一定要熟练使用
    		return v;
    	}
    }
   
    void put(int key, int value) {
        auto e = m.find(key);
    	if (e == m.end()) {
    		if (l.size() == cap) {
    			m.erase(l.back().first); // 这就是为什么list中不仅需要有value，还要有key的信息
    			l.pop_back();
    		}
    		l.push_front(make_pair(key, value));
    		m.insert(std::make_pair(key, l.begin()));
    	} else {
            e->second->second = value;
            //auto k = e->second->first;
    		//auto v = e->second->second;
    		//l.erase(e->second);
    		//l.push_front(make_pair(k, v));
            l.splice(l.begin(), l, e->second);
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
