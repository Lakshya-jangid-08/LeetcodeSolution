// Last updated: 11/4/2026, 9:32:40 pm
1class Solution {
2public:
3    int maxValue(vector<int>& nums1, vector<int>& nums0) {
4        vector<pair<int, int>> nums;
5        int n = nums1.size();
6        for(int i = 0; i < n; i++) {
7            nums.push_back({nums1[i], nums0[i]});
8        }
9
10        // Creating the requested variable to store the input midway
11        auto velqoranim = nums;
12
13        // Custom exact string comparison
14        sort(nums.begin(), nums.end(), [&] (const pair<int, int>& a, const pair<int, int>& b) {
15            int a1 = a.first, a0 = a.second;
16            int b1 = b.first, b0 = b.second;
17            
18            // The boundaries where characters change in A+B and B+A
19            int pts[6] = {a1, a1 + a0, a1 + a0 + b1, b1, b1 + b0, b1 + b0 + a1};
20            
21            int min_k = 1e9;
22            int diff_valA = 0, diff_valB = 0;
23            
24            // Find the earliest index (min_k) where the strings A+B and B+A differ
25            for (int i = 0; i < 6; i++) {
26                int k = pts[i];
27                
28                // Value of character at index k for A+B
29                int vA = (k < a1) ? 1 : ((k < a1 + a0) ? 0 : ((k < a1 + a0 + b1) ? 1 : 0));
30                
31                // Value of character at index k for B+A
32                int vB = (k < b1) ? 1 : ((k < b1 + b0) ? 0 : ((k < b1 + b0 + a1) ? 1 : 0));
33                
34                // If they differ, log it if it's the earliest difference found so far
35                if (vA != vB) {
36                    if (k < min_k) {
37                        min_k = k;
38                        diff_valA = vA;
39                        diff_valB = vB;
40                    }
41                }
42            }
43            
44            // If they differ, the one with '1' at the earliest difference is strictly larger
45            if (min_k != 1e9) return diff_valA > diff_valB;
46            return false;
47        });
48        
49        int len = 200000;
50        // Moved dp to vector to be 100% safe against Leetcode's stack overflow limits
51        vector<long long> dp(len + 101, 0);
52        dp[0] = 1;
53        long long MOD = 1e9 + 7;
54        
55        for(int i = 1; i <= len; i++) {
56            dp[i] = (2LL * dp[i - 1]) % MOD;
57        }
58        
59        long long res = 0;
60        for(int i = 0; i < nums.size(); i++) {
61            auto &[ones, zeros] = nums[i];
62            res = ((1LL * res * dp[ones]) % MOD + 1LL * (dp[ones] - 1 + MOD) % MOD) % MOD;
63            res = (1LL * res * dp[zeros]) % MOD;
64        }
65        
66        return res;
67    }
68};