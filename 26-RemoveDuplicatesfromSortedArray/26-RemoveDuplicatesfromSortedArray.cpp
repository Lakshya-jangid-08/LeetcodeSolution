// Last updated: 8/14/2026, 8:56:59 PM
1class Solution {
2public:
3    int removeDuplicates(vector<int>& nums) {
4        if(nums.size() == 0) return 0;
5        int idx = 0;
6
7        for(int i = 1; i < nums.size(); i++) {
8            if(nums[i] != nums[idx]) {
9                nums[++idx] = nums[i];
10            }
11        }
12        return idx + 1;
13    }
14};