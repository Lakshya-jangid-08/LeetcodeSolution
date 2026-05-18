// Last updated: 5/18/2026, 11:27:16 PM
1class Solution {
2    vector<int> dp;
3    bool solve(vector<int>& nums, int idx) {
4        if(idx >= nums.size()) return false;
5        if(idx == nums.size() - 1) return true;
6
7        if(dp[idx] != -1) return dp[idx];
8
9        bool res = false;
10
11        for(int i = 1; i <= nums[idx]; i++) {
12            res = res | solve(nums, idx + i);
13            if(res == true) return dp[idx] = true;
14        }        
15        return dp[idx] = res;
16    }
17public:
18    bool canJump(vector<int>& nums) {
19        dp.resize(nums.size(), -1);
20        return solve(nums, 0);
21    }
22};