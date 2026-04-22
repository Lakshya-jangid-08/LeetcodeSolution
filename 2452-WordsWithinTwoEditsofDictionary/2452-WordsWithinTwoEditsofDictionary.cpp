// Last updated: 4/22/2026, 9:38:40 AM
1class Solution {
2public:
3    vector<string> twoEditWords(vector<string>& query, vector<string>& dic) {
4        vector<string> res;
5        int n = dic[0].length();
6
7        const auto isMatch = [&](string s, string t) -> bool {
8            if(s == t) return true;
9            int cnt = 0;
10            for(int i = 0; i < n; i++) {
11                if(s[i] != t[i]) cnt++; 
12            }
13            return (cnt <= 2);
14        };
15        vector<bool> isAns(query.size(), false);
16        for(auto &d : dic) {
17            int i = 0;
18            for(auto &q : query) {
19                if(isMatch(d, q)) {
20                    isAns[i] = true;
21                }
22                i++;
23            }
24        }
25
26        for(int i = 0; i < isAns.size(); i++) {
27            if(isAns[i] == false) continue;
28            res.push_back(query[i]);
29        }
30
31        return res;
32    }
33};