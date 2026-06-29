// Last updated: 6/29/2026, 10:19:29 AM
class Solution {
public:
    const int MOD = 1e9 + 7;
    int maxValue(vector<int>& nums1, vector<int>& nums0) {
        int n = nums1.size();
        vector<pair<int, int>> nums;

        for(int i = 0; i < n; i++) {
            nums.push_back({nums1[i], nums0[i]});
        }

        sort(nums.begin(), nums.end(), [&](auto &a, auto &b) {
            auto& [a1, a2] = a;
            auto& [b1, b2] = b;

            string s1(a1, '1');
            string s2(a2, '0');
            string s3(b1, '1');
            string s4(b2, '0');

            s1 = s1 + s2;
            s3 = s3 + s4;

            return s1 + s3 > s3 + s1;
        });

        long long dp[100001] = {0};
        dp[0] = 1;
        for(int i = 1; i < 100000; i++) {
            dp[i] = (2LL * dp[i - 1] ) % MOD;
        }
        
        int res = 0;
        for(int i = 0; i < n; i++) {
            auto &[ones, zeros] = nums[i];
            res = (res * dp[ones] + dp[ones] - 1) % MOD;
            res = (res * dp[zeros]) % MOD;
        }
        return res;
    }
};