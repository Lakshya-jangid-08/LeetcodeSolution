// Last updated: 6/29/2026, 10:22:46 AM
class RandomizedSet {
    private:vector<int> st;
    private:unordered_map<int, int> mp;
    public:RandomizedSet() {}
    
    public:bool insert(int val) {
        if(mp.count(val)) return false;
        st.push_back(val);
        mp[val] = st.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(mp.count(val) == 0) return false;
        int lastVal = st.back();
        int idx = mp[val];
        st[idx] = lastVal;
        st.pop_back();
        mp[lastVal] = idx;
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        return st[rand() % st.size()]; 
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */