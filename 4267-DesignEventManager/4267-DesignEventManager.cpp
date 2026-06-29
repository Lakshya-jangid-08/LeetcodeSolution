// Last updated: 6/29/2026, 10:19:40 AM
class EventManager {

struct cmp {
    bool operator()(const pair<int,int>& a, const pair<int,int>& b) const {
        if (a.first != b.first)
            return a.first > b.first;   
        return a.second < b.second;     
    }
};
    set<pair<int, int>, cmp> s;
    unordered_map<int, int> mp;
public:
    EventManager(vector<vector<int>>& events) {
        for(auto e : events) {
            s.insert({e[1], e[0]});
            mp[e[0]] = e[1];
        }
    }
    
    void updatePriority(int eventId, int newPriority) {
        int prevPrio = mp[eventId];
        s.erase({prevPrio, eventId});
        s.insert({newPriority, eventId});
        mp[eventId] = newPriority;
    }
    
    int pollHighest() {
        if(s.empty()) return -1;
        auto it = s.begin();
        auto val = *it;
        s.erase(it);
        return val.second;
        
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */