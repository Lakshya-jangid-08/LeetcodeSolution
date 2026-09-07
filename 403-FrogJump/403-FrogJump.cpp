// Last updated: 9/7/2026, 11:28:54 PM
1class Solution {
2public:
3    bool canCross(vector<int>& stones) {
4        int n = stones.size();
5        vector<vector<int>> dp(n, vector<int>(n + n + 1, -1));
6
7        const auto solve = [&](auto &&func, int idx, int k) -> bool {
8            if(k == 0) return (idx == n - 1);
9            if(idx == n-1) return true;
10            if(idx >= n) return false;
11
12            if(dp[idx][k] != -1) return dp[idx][k];
13 
14            int nextIdx = lower_bound(stones.begin(), stones.end(), stones[idx] + k) - stones.begin();
15            // >= v + k;
16
17            if(nextIdx == n) return false;
18            if(stones[idx] + k != stones[nextIdx]) return false;
19            
20            return dp[idx][k] = func(func, nextIdx, k + 1) or
21            func(func, nextIdx, k - 1) or
22            func(func, nextIdx, k);
23        };
24
25        return solve(solve, 0, 1);
26    }
27};