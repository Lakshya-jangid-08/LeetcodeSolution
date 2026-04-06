// Last updated: 7/4/2026, 12:48:55 am
1class Solution {
2    int dp[1001][1001];
3    int solve(string &s, int st, int end) {
4        if(st == end) return 1;
5        if(st > end) return 0;
6        if(dp[st][end] != -1) return dp[st][end];
7        int res = 0;
8        if(s[st] == s[end]) {
9            res = 2 + solve(s, st + 1, end - 1); 
10        } else {
11            res = max(res, solve(s, st + 1, end));
12            res = max(res, solve(s, st, end - 1));
13        }
14        return dp[st][end] = res;
15    }
16public:
17    int longestPalindromeSubseq(string s) {
18        int n = s.length();
19        memset(dp, -1, sizeof(dp));
20        return solve(s, 0, n - 1);
21    }
22};