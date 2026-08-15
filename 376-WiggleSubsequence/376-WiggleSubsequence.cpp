// Last updated: 8/15/2026, 6:57:07 PM
1class Solution {
2public:
3    int wiggleMaxLength(vector<int>& nums) {
4        int n = nums.size();
5        vector<vector<int>> dp(n, vector<int>(2, -1));
6        const auto solve = [&](auto &&self, int idx, int isUp) -> int {
7            if(idx == n) return 0;
8            int &res = dp[idx][isUp];
9            if(res != -1) return res;
10
11            res = 0;
12            for(int i = idx + 1; i < n; i++) {
13                int cnt = 0;
14                if(isUp && nums[idx] < nums[i]) {
15                    cnt = 1 + self(self, i, !isUp);
16                } 
17                if(!isUp && nums[idx] > nums[i]) {
18                    cnt = 1 + self(self, i, !isUp);
19                }
20                res = max(res, cnt);
21            }
22            return res;
23        };
24
25        int res = 0;
26        for(int i = 0; i < n; i++) {
27            int a = 1 + solve(solve, i, 1);
28            int b = 1 + solve(solve, i, 0);
29            res = max({res, a, b});
30        }
31        return res;
32    }
33};