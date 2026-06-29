// Last updated: 6/29/2026, 10:23:38 AM
class Solution {
    int dp[501][501];
    int solve(string& s, int idx1, string& t, int idx2) {
        if(idx2 == t.length()) {
            return s.length() - idx1;
        }
        if(idx1 == s.length()) {
            return t.length() - idx2;
        }

        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];

        if(s[idx1] == t[idx2]) 
            return dp[idx1][idx2] =  solve(s, idx1 + 1, t, idx2 + 1);
        return dp[idx1][idx2] = min({1 + solve(s, idx1, t, idx2 + 1), 1 + solve(s, idx1 + 1, t, idx2), 1 + solve(s, idx1 + 1, t, idx2 + 1)});
    }

public:
    int minDistance(string word1, string word2) {
        memset(dp, -1, sizeof(dp));
        return solve(word1, 0, word2, 0);
    }
};