// Last updated: 6/4/2026, 9:39:16 pm
1class Solution {
2public:
3    int alternatingSum(vector<int>& nums) {
4        long int res = 0;
5        for(int i = 0; i < nums.size(); i++) {
6            res += (i&1 ? - nums[i] : nums[i]);
7        }
8        return res;
9    }
10};