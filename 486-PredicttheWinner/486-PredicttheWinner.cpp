// Last updated: 8/1/2026, 11:29:47 PM
1class Solution {
2public:
3    bool predictTheWinner(vector<int>& A) {
4        int n = A.size();
5        if (~n & 1) return true;
6
7        vector<int> dp(n);
8
9        for (int i = n - 1; i >= 0; i--) {
10            dp[i] = A[i];
11            for (int j = i + 1; j < n; j++)
12                dp[j] = max(A[i] - dp[j], A[j] - dp[j - 1]);
13        }
14
15        return dp[n - 1] >= 0;
16    }
17};