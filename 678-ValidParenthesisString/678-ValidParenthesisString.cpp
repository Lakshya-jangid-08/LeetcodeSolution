// Last updated: 6/2/2026, 10:32:15 AM
1class Solution {
2public:
3    int n = 0;
4    vector<vector<int>> dp;
5
6
7    bool solve(string &s, int idx, int bal) {
8        if(bal < 0) return false;
9        if(idx == n) return bal == 0;
10
11        if(dp[idx][bal] != -1) return dp[idx][bal];
12
13        bool ans = false;
14        if(s[idx] == '(') {
15            ans = solve(s, idx + 1, bal + 1);
16        } else if (s[idx] == ')') {
17            ans = solve(s, idx + 1, bal - 1);
18        } else {
19            ans = solve(s, idx + 1, bal + 1) || solve(s, idx + 1, bal - 1) ||solve(s, idx + 1, bal + 0);
20        }
21        return dp[idx][bal] = ans;
22    }
23
24    bool checkValidString(string s) {
25        
26        n = s.length();
27        dp.resize(n, vector<int>(n + 2, -1));
28    
29        return solve(s, 0, 0);
30
31    }
32};