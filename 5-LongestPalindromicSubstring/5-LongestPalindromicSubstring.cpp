// Last updated: 6/29/2026, 10:24:00 AM
class Solution {
    
    int dp[1001][1001];

    bool solve(string &s, int l, int r) {
        if(l >= r) return dp[l][r] = true;

        if(dp[l][r] != -1) return dp[l][r];

        dp[l][r] = false;
        if(s[l] == s[r]) {
            dp[l][r] = solve(s, l + 1, r - 1);
        }
        solve(s, l + 1, r);
        solve(s, l, r - 1);
        return dp[l][r];
    }

public:
    string longestPalindrome(string s) {
        memset(dp, -1, sizeof(dp));
        int n = s.length();
        dp[0][n - 1] = solve(s, 0, n - 1);
        int st = -1;
        int maxLen = -1;
        
        for(int l = 0; l < n; l++) {
            for(int r = l; r < n; r++) {
                if(dp[l][r] == 1 && maxLen < r + 1 - l) {
                    maxLen = r + 1 - l;
                    st = l;
                }
            }
        }

        string res = "";
        if(st != -1) res = s.substr(st, maxLen);
        return res; 
    }
};