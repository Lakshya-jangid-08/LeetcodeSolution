// Last updated: 6/29/2026, 10:23:45 AM
class Solution {
    vector<vector<int>> dp;
    bool isMatch(string& s, int idx1, string& p, int idx2) {
        if(idx1 == s.length() && idx2 == p.length()) return true;
        if(idx2 == p.length()) return false;
        if(idx1 == s.length()) {
            while(idx2 < p.length()) {
                if(p[idx2] != '*') return false;
                idx2 += 1;
            }
            return true;
        }

        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];

        if(s[idx1] == p[idx2]) 
            return dp[idx1][idx2] = isMatch(s, idx1 + 1, p, idx2 + 1);
        if(p[idx2] == '?')
            return dp[idx1][idx2] = isMatch(s, idx1 + 1, p, idx2 + 1);
        if(p[idx2] == '*')
            return dp[idx1][idx2] = isMatch(s, idx1, p, idx2 + 1) || isMatch(s, idx1 + 1, p, idx2);
        return false;
    }

public:
    bool isMatch(string s, string p) {
        dp.assign(
            s.length() + 1,
            vector<int>(p.length() + 1, -1)
        );
        return isMatch(s, 0, p, 0);
    }
};