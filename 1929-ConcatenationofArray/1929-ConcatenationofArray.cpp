// Last updated: 4/26/2026, 1:20:42 PM
1class Solution {
2public:
3    int findMaxConsecutiveOnes(vector<int>& nums) {
4        int l = -1, r = 0;
5        int ans = 0;
6        for(int i = 0; i < nums.size(); i++) {
7            if(nums[i] == 1) {
8                r = i;
9            }
10            else {
11                l = i;
12            }
13            ans = max(ans,r-l);
14        }
15        return ans;
16    }
17};