// Last updated: 8/6/2026, 1:19:10 AM
1class Solution {
2public:
3    string longestPalindrome(string s) {
4        int n = s.length();
5        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
6
7        const auto solve = [&](auto &&self, int l, int r) -> bool {
8            if(r <= l) return true;
9            int &res = dp[l][r];
10            if(res != -1) return res;
11            
12            res = 0;
13            if(s[l] == s[r]) {
14                res = 1 && self(self, l + 1, r - 1);
15            }
16
17            self(self, l + 1, r);
18            self(self, l, r - 1);
19
20            return res = res | false;
21        };
22
23        solve(solve, 0, n - 1);
24        int maxLen = 1;
25        int st = 0;
26        for(int l = 0; l < n; l++) {
27            for(int r = l; r < n; r++) {
28                if(dp[l][r] && r - l + 1 > maxLen) {
29                    maxLen = r - l + 1;
30                    st = l;
31                }
32            }
33        }
34
35
36        return s.substr(st, maxLen);
37
38    }
39};