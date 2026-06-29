// Last updated: 6/29/2026, 10:20:50 AM
class Solution {
public:
    unordered_map<int , unordered_map<int, bool>> dp;
    
    bool solve(string s, int n, string t, int m) {
        if(s == t) return true;
        if(n == s.length() || m == t.length()) return false;

        if(dp[n].count(m)) return dp[n][m];

        string prev = s;
        swap(s[n], s[n + 2]);
        bool a = solve(s, n + 1, t, m);
        
        swap(t[m], t[m + 2]);
        bool b = solve(prev, n, t, m + 1);

        return dp[n][m] = (a | b);

    }

    bool canBeEqual(string s1, string s2) {
        if(s1 == s2) return true;
        return solve(s1, 0, s2, 0);
    }
};