// Last updated: 8/21/2026, 5:03:53 PM
1class Solution {
2public:
3    int numDistinct(string s, string t) {
4        int n = s.length(), m = t.length();
5        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 0));
6
7        for(int j = 0; j <= m; j++) {
8            dp[n][j] = 0;
9        }
10        for(int i = 0; i <= n; i++) {
11            dp[i][m] = 1;
12        }
13
14        for(int i = n - 1; i >= 0; i--) {
15            for(int j = m - 1; j >= 0; j--) {
16                int res = 0;
17                if(s[i] == t[j]) {
18                    res = res + dp[i + 1][j + 1]; 
19                }
20                res = res + dp[i + 1][j];
21                dp[i][j] = res;
22            }
23        }
24
25        return dp[0][0];
26    }
27};