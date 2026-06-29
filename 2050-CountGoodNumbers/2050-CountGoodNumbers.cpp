// Last updated: 6/29/2026, 10:21:18 AM
class Solution {
    int MOD = 1e9 + 7;
    long long pow(long long x, long long y) {
        long long res = 1;

        while(y > 0) {
            if(y&1) res = (res * x) % MOD;
            x = (x * x) % MOD;
            y /= 2;
        }

        return res;
    }

public:
    int countGoodNumbers(long long n) {
        long long res = 1;
        long long oddIdx = (n) / 2;
        long long evenIdx = (n + 1) / 2;

        res = (pow(5,evenIdx) * pow(4, oddIdx)) % MOD;

        return res;
    }
};