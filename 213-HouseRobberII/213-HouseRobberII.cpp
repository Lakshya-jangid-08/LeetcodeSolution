// Last updated: 5/4/2026, 10:30:05 pm
1class Solution {
2public:
3    int rob(vector<int>& nums) {
4        int n = nums.size();
5        if(n == 1) return nums[0];
6        int prev1 = 0, prev2 = 0, curr = 0;
7        for(int i = n - 2; i >= 0; i--) {
8            curr = max(prev1, nums[i] + prev2);
9            prev2 = prev1;
10            prev1 = curr;
11        }   
12
13        int res = curr;
14        prev1 = 0; prev2 = 0;
15        for(int i = n - 1; i >= 1; i--) {
16            curr = max(prev1, nums[i] + prev2);
17            prev2 = prev1;
18            prev1 = curr;
19        }
20
21        return max(res, curr);
22    }
23};