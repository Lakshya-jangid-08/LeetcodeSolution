// Last updated: 6/29/2026, 10:23:22 AM
class LRUCache {
    unordered_map<int, list<pair<int, int>> :: iterator> cache;
    list<pair<int, int>> ll;
    int cap;
public:
    LRUCache(int capacity) {
        this->cap = capacity;
    }
    
    int get(int key) {
        if(cache.count(key)) {
            
            auto it = cache[key];
            auto [key, val] = *it;

            ll.erase(it);
            ll.push_front({key, val});
            cache[key] = ll.begin();
            return val;
        } else return -1;
    }
    
    void put(int key, int value) {
        // check already exist or not
        // if exist then go front of list
        if(cache.count(key)) {
            auto it = cache[key];
            ll.erase(it);
        } 
        // if key doesnot exist then insert but care about cap
        else if(ll.size() == cap) {
            int k = ll.back().first;
            cache.erase(k);
            ll.pop_back();
        }
        ll.push_front({key, value});
        cache[key] = ll.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */