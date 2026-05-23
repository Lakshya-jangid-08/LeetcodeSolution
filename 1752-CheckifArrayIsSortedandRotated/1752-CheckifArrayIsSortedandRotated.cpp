// Last updated: 5/23/2026, 10:25:18 PM
1class Solution {
2public:
3    bool check(vector<int>& nums) {
4        int pivot = 1;
5
6        for(int i = 1; i < nums.size(); i++) {
7            if(nums[i] < nums[i-1]) pivot--;
8        }
9        if(nums[0] < nums[nums.size() - 1]) pivot--;
10        return (pivot >= 0);
11    }
12};