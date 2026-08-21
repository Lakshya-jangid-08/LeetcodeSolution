// Last updated: 8/21/2026, 2:01:50 PM
1class Solution {
2public:
3    int longestOnes(vector<int>& nums, int k) {
4        int l = 0, r = 0;
5        int flip = k;
6        int len = 0;
7        while(r < nums.size()) {
8            while(nums[r] == 0 && flip == 0) {
9                if(nums[l] == 0) flip++;
10                l++;
11            }
12            if(!nums[r]) flip--;
13            len = max(len, r - l + 1);
14            r++;
15        }
16        return len;
17    }
18};