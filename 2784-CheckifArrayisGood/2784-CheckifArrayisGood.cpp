// Last updated: 5/14/2026, 1:51:01 PM
1class Solution {
2public:
3    bool isGood(vector<int>& nums) {
4
5        int m = nums.size();
6
7        if(m < 2)
8            return false;
9
10        sort(nums.begin(), nums.end());
11
12        int n = m - 1;
13
14        for(int i = 0; i < n - 1; i++) {
15            if(nums[i] != i + 1)
16                return false;
17        }
18
19        return nums[n - 1] == n && nums[n] == n;
20    }
21};