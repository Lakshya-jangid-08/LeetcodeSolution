// Last updated: 6/29/2026, 10:22:36 AM
class LFUCache {
    unordered_map<int, int> keyToFreq;
    map< int, list<pair<int,int>> > freqToDll;
    unordered_map< int, list<pair<int, int>> :: iterator > keyToIt;
    int cap;
public:
    LFUCache(int capacity) {
        this->cap = capacity;
    }
    
    int get(int key) {
        if(keyToIt.count(key) == 0) return -1;

        auto it = keyToIt[key];
        auto [k, val] = *it;
        
        int freq = keyToFreq[key];
        freqToDll[freq].erase(it);
        if(freqToDll[freq].empty())
            freqToDll.erase(freq);
        freq += 1;

        freqToDll[freq].push_front({key, val});
        keyToFreq[key] = freq;
        keyToIt[key] = freqToDll[freq].begin();

        return val;
    }
    
    void put(int key, int value) {
        if(keyToIt.count(key)) {
            // matlab exist krta hai;
            auto it = keyToIt[key];
            int freq = keyToFreq[key];
            freqToDll[freq].erase(it);
            if(freqToDll[freq].empty())
                freqToDll.erase(freq);

        } else if(cap == keyToIt.size()) {
            // size full hai;
            int freq = freqToDll.begin()->first;
            auto [k,v] = freqToDll[freq].back();
            keyToFreq.erase(k);
            keyToIt.erase(k);
            freqToDll[freq].pop_back();
            if(freqToDll[freq].empty())
                freqToDll.erase(freq);
        }

        int freq = keyToFreq[key];
        freq += 1;
        keyToFreq[key] = freq;
        freqToDll[freq].push_front({key, value});
        keyToIt[key] = freqToDll[freq].begin();
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */