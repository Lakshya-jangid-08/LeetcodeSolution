// Last updated: 6/4/2026, 10:17:42 pm
1class Solution {
2public:
3    int longestSubsequence(vector<int>& nums) {
4        int Xor = 0;
5        bool onlyZero = true;
6
7        for(int i = 0; i < nums.size(); i++) {
8            Xor ^= nums[i];
9            if(nums[i]) onlyZero = false;
10        }
11        
12        if(onlyZero) return 0;
13        if(Xor != 0) return nums.size();
14        return nums.size() - 1;
15    }
16};