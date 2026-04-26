// Last updated: 4/26/2026, 1:22:24 PM
1class Solution {
2public:
3    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
4        int n = nums.size();
5        vector<int>res(n);
6        for(int i = 0; i < n; i++) {
7            int cnt = 0;
8            int val = nums[i];
9            for(int j = 0; j < n; j++) {
10                if(val > nums[j]) cnt++;
11            }
12            res[i] = cnt;
13        }
14        return res;
15    }
16};