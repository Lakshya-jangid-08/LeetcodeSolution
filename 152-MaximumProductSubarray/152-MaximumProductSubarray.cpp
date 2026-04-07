// Last updated: 8/4/2026, 1:56:38 am
1class Solution {
2public:
3    vector<pair<int,int>> dp; // {maxProd, minProd}
4
5    pair<int,int> solve(vector<int>& nums, int i) {
6        if (i == 0) return {nums[0], nums[0]};
7
8        if (dp[i].first != INT_MIN) return dp[i];
9
10        auto prev = solve(nums, i - 1);
11
12        int curr = nums[i];
13
14        int mx = max({curr, curr * prev.first, curr * prev.second});
15        int mn = min({curr, curr * prev.first, curr * prev.second});
16
17        return dp[i] = {mx, mn};
18    }
19
20    int maxProduct(vector<int>& nums) {
21        int n = nums.size();
22        dp.resize(n, {INT_MIN, INT_MIN});
23
24        int ans = nums[0];
25
26        for (int i = 0; i < n; i++) {
27            auto res = solve(nums, i);
28            ans = max(ans, res.first);
29        }
30
31        return ans;
32    }
33};