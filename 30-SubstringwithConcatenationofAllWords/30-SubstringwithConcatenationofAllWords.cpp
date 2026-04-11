// Last updated: 11/4/2026, 4:23:13 pm
1class Solution {
2public:
3    vector<int> findSubstring(string s, vector<string>& words) {
4        unordered_map<string , int> mp;
5
6        for(auto & w : words) {
7            mp[w]++;
8        }
9        
10        int len = words[0].size();
11        int n = words.size();
12        int m = s.length();
13
14        if(m < n * len) return {};
15        vector<int> res;
16        for(int offset = 0; offset < len; offset++) {
17            auto dup = mp;
18            int l = offset;
19            int cnt = 0;
20            for(int r = offset; r < m; r += len) {
21                string sub = s.substr(r, len);
22                
23                if(dup.count(sub) == 0) {
24                    dup = mp;
25                    cnt = 0;
26                    l = r + len;
27                } else {
28                    
29                    while(dup[sub] == 0) {
30                        string sub2 = s.substr(l, len);
31                        dup[sub2]++;
32                        cnt--; l += len;
33                    }
34
35                    dup[sub]--;
36                    cnt++;
37                }
38                if(cnt == n) {
39                    res.push_back(l);
40                    string sub2 = s.substr(l, len);
41                    dup[sub2]++;
42                    l += len;
43                    cnt--;
44                }
45            }
46        }
47        return res;
48    }
49};