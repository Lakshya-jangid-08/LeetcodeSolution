// Last updated: 5/25/2026, 10:20:50 AM
1class Solution {
2    vector<int> dp;
3    int solve(vector<int>& nums, int idx) {
4        if(idx >= nums.size() - 1) return 0;
5
6        if(dp[idx] != -1) return dp[idx];
7
8        int res = 1e7;
9        if(nums[idx] == 0) return res;
10
11        for(int i = 1; i <= nums[idx]; i++) {
12            if(idx + i == nums.size()) break;
13            res = min(res, 1 + solve(nums, idx + i));
14        }        
15
16        return dp[idx] = res;
17    }
18public:
19    int jump(vector<int>& nums) {
20        dp.resize(nums.size(), -1);
21        return solve(nums, 0);
22    }
23};