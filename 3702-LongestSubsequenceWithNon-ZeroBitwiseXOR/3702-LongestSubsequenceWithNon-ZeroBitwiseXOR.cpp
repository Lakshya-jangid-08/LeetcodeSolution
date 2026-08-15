// Last updated: 8/15/2026, 10:02:50 AM
1class Solution {
2public:
3    int longestSubsequence(vector<int>& nums) {
4        int XOR = nums[0];
5        int isNonZero = (nums[0] > 0) ? 1 : 0;
6        for(int i = 1; i < nums.size(); i++) {
7            XOR ^= nums[i];
8            if(nums[i] > 0) isNonZero = 1;
9        }
10
11        if(!isNonZero) return 0;
12
13        return (XOR > 0) ? nums.size() : nums.size() - 1;
14    }
15};