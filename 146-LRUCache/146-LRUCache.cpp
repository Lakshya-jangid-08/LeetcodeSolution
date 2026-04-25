// Last updated: 4/25/2026, 8:56:24 PM
1// class Node {
2//     int val;
3//     Node * next; 
4//     Node * prev;
5// }
6
7class LRUCache {
8    unordered_map< int, list<pair<int, int>> :: iterator> cache;
9    list<pair<int, int>> ll; 
10    int cap;
11public:
12    LRUCache(int capacity) {
13        cap = capacity;
14    }
15    
16    int get(int key) {
17        auto it = cache.find(key);
18        if(it == cache.end()) return -1; 
19        auto listIt = it->second; 
20        int val = listIt->second;
21
22        ll.erase(listIt);
23
24        ll.push_front({key, val});
25        cache[key] = ll.begin();
26        return val;
27    }
28    
29    void put(int key, int value) {
30        
31        if(cache.count(key)) {
32            auto it = cache[key];
33            ll.erase(it);
34        } else if(ll.size() == cap) {
35
36            int k = ll.back().first;
37            cache.erase(k);
38            ll.pop_back();
39
40        }
41        ll.push_front({key, value});
42        cache[key] = ll.begin();
43    }
44};
45
46/**
47 * Your LRUCache object will be instantiated and called as such:
48 * LRUCache* obj = new LRUCache(capacity);
49 * int param_1 = obj->get(key);
50 * obj->put(key,value);
51 */