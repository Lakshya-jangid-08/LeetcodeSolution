// Last updated: 7/26/2026, 10:48:14 AM
1class Solution {
2public:
3    int maximumProduct(vector<int>& nums) {
4        sort(nums.begin(), nums.end());
5        int n = nums.size();
6        return max({
7            nums[0] * nums[1] * nums[2],
8            nums[0] * nums[1] * nums[n - 1],
9            nums[0] * nums[n - 2] * nums[n - 1],
10            nums[n - 3] * nums[n - 2] * nums[n - 1]
11        });
12    }
13};