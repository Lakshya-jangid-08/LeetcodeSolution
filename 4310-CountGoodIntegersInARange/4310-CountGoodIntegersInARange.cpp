// Last updated: 6/29/2026, 10:19:16 AM
class Solution {
public:
    // idx, lz, tight, prev
    long long dp[17][2][2][11];

    long long solve(string &s, int idx, int lz, int tight, int prev, int k) {
        if(s.length() == idx) return 1;

        if(dp[idx][lz][tight][prev] != -1) return dp[idx][lz][tight][prev];
        
        int lb = 0;
        int ub = (tight) ? s[idx] - '0' : 9;

        long long res = 0;
        
        for(int dig = lb; dig <= ub; dig++) {
            if(!lz && abs(prev - dig) > k) continue;
            int currLz = (dig == 0) && lz;
            int currTight = (dig == ub) && tight;
            res += solve(s, idx + 1, currLz, currTight, (currLz == 0) ? dig : 10, k);
        }
        return dp[idx][lz][tight][prev] = res;
    }
    
    long long goodIntegers(long long l, long long r, int k) {

        string ls = to_string(l - 1);
        string rs = to_string(r);

        memset(dp, -1, sizeof(dp));
        long long ans_l = solve(ls, 0, 1, 1, 10, k);
        memset(dp, -1, sizeof(dp));
        long long ans_r = solve(rs, 0, 1, 1, 10, k);
        return ans_r - ans_l;
    }
};