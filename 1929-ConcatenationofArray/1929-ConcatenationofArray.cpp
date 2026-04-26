// Last updated: 4/26/2026, 1:20:20 PM
1class Solution {
2public:
3    vector<int> shuffle(vector<int>& nums, int n) {
4        vector<int>res (2*n);
5        int j = 0;
6        for(int i = 0; i < n; i++) {
7            res[j] = nums[i];
8            res[j+1] = nums[i + n];
9            j+=2;
10        }
11        return res;
12    }
13};