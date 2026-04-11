// Last updated: 12/4/2026, 12:39:39 am
1class Solution {
2public:
3    const int MOD = 1e9 + 7;
4    int maxValue(vector<int>& nums1, vector<int>& nums0) {
5        int n = nums1.size();
6        vector<pair<int, int>> nums;
7
8        for(int i = 0; i < n; i++) {
9            nums.push_back({nums1[i], nums0[i]});
10        }
11
12        sort(nums.begin(), nums.end(), [&](auto &a, auto &b) {
13            auto& [a1, a2] = a;
14            auto& [b1, b2] = b;
15
16            string s1(a1, '1');
17            string s2(a2, '0');
18            string s3(b1, '1');
19            string s4(b2, '0');
20
21            s1 = s1 + s2;
22            s3 = s3 + s4;
23
24            return s1 + s3 > s3 + s1;
25        });
26
27        long long dp[100001] = {0};
28        dp[0] = 1;
29        for(int i = 1; i < 100000; i++) {
30            dp[i] = (2LL * dp[i - 1] ) % MOD;
31        }
32        
33        int res = 0;
34        for(int i = 0; i < n; i++) {
35            auto &[ones, zeros] = nums[i];
36            res = (res * dp[ones] + dp[ones] - 1) % MOD;
37            res = (res * dp[zeros]) % MOD;
38        }
39        return res;
40    }
41};