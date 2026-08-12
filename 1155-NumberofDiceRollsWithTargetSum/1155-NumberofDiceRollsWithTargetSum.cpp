// Last updated: 8/12/2026, 2:19:12 PM
1class Solution {
2public:
3    int numRollsToTarget(int n, int k, int target) {
4        int dp[30][1000];
5        memset(dp, -1, sizeof(dp));
6        int MOD = 1e9 + 7;
7        const auto solve = [&](auto &&self, int idx, int sum) -> int {
8            if (sum > target)
9                return 0;
10
11            if (sum == target)
12                return idx == n;
13                
14            if(idx == n)  return 0;
15
16            int &res = dp[idx][sum];
17            if(res != -1) return res;
18            res = 0;
19            
20            for(int i = 1; i <= k; i++) {
21                int val = self(self, idx + 1, sum + i);
22                res = (1LL * res + 1LL * val) % MOD;
23            }
24
25            return res % MOD;
26        };
27
28        return solve(solve, 0, 0);
29    }
30};