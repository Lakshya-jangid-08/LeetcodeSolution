// Last updated: 6/29/2026, 10:20:45 AM
class Solution {
public:
    long long dp[17][2];

    long long func(string &s, int idx, int tight, int limit, string &suffix) {
        if(idx > (int)s.length() - (int)suffix.length()) return 0;
        if(idx == (int)s.length() - (int)suffix.length()) {
            if(tight) {
                return s.substr(idx) >= suffix;
            }
            return 1;
        }

        if(dp[idx][tight] != -1) return dp[idx][tight]; 

        int lb = 0;
        int maxDig  = s[idx] - '0';
        int ub = (tight ? maxDig : 9);
        ub = min(ub, limit);

        long long cnt = 0;
        for(int i = 0; i <= ub; i++) {
            cnt += func(s, idx + 1, tight && (maxDig == i), limit, suffix);
        }
        return dp[idx][tight] = cnt;
    }

    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        // ans = r - (l - 1);
        // store kya kya krna hai
        // idx, tight, lz,
        memset( dp, -1, sizeof(dp) );
        string l = to_string(start - 1);
        long long left = func(l, 0, 1, limit, s);

        memset(dp, -1, sizeof(dp));
        string r = to_string(finish);
        long long right = func(r, 0, 1, limit, s);


        return right - left;

    }
};