// Last updated: 8/20/2026, 2:49:00 PM
1class Solution {
2    int n;
3    int total;
4    vector<vector<int>> dp;
5
6    int solve(vector<int>& nums, int idx, int diff) {
7        if (idx == n) {
8            return abs(diff);
9        }
10
11        int d = diff + total;
12
13        if (dp[idx][d] != -1) {
14            return dp[idx][d];
15        }
16
17        int takePositive = solve(nums, idx + 1, diff + nums[idx]);
18        int takeNegative = solve(nums, idx + 1, diff - nums[idx]);
19
20        return dp[idx][d] = min(takePositive, takeNegative);
21    }
22
23public:
24    int lastStoneWeightII(vector<int>& stones) {
25        n = stones.size();
26
27        total = accumulate(stones.begin(), stones.end(), 0);
28
29        dp.assign(n, vector<int>(2 * total + 1, -1));
30
31        return solve(stones, 0, 0);
32    }
33};