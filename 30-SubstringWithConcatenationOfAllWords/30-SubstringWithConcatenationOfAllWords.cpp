// Last updated: 6/29/2026, 10:23:52 AM
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string , int> mp;

        for(auto & w : words) {
            mp[w]++;
        }
        
        int len = words[0].size();
        int n = words.size();
        int m = s.length();

        if(m < n * len) return {};
        vector<int> res;
        for(int offset = 0; offset < len; offset++) {
            auto dup = mp;
            int l = offset;
            int cnt = 0;
            for(int r = offset; r < m; r += len) {
                string sub = s.substr(r, len);
                
                if(dup.count(sub) == 0) {
                    dup = mp;
                    cnt = 0;
                    l = r + len;
                } else {
                    
                    while(dup[sub] == 0) {
                        string sub2 = s.substr(l, len);
                        dup[sub2]++;
                        cnt--; l += len;
                    }

                    dup[sub]--;
                    cnt++;
                }
                if(cnt == n) {
                    res.push_back(l);
                    string sub2 = s.substr(l, len);
                    dup[sub2]++;
                    l += len;
                    cnt--;
                }
            }
        }
        return res;
    }
};