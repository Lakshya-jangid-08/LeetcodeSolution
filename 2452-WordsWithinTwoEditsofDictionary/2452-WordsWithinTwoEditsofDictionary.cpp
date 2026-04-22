// Last updated: 4/22/2026, 9:41:44 AM
1class Solution {
2public:
3    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
4        vector<string> ans;
5        int n = queries[0].length();
6        const auto isMatch = [&](string s, string t) -> bool {
7            if(s == t) return true;
8            int cnt = 0;
9            for(int i = 0; i < n; i++) {
10                if(s[i] != t[i]) cnt++; 
11            }
12            return (cnt <= 2);
13        };
14
15        for (auto &query : queries) {
16            for (auto &s : dictionary) {
17                if (isMatch(s, query)) {
18                    ans.push_back(query);
19                    break;
20                }
21            }
22        }
23        return ans;
24    }
25};