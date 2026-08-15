// Last updated: 8/15/2026, 7:11:52 PM
1class Solution {
2public:
3    int wiggleMaxLength(vector<int>& nums) {
4        int up = 1, down = 1;
5
6        for(int i = 1; i <= nums.size() - 1; i++) {
7            if(nums[i] > nums[i - 1]) 
8                up = down + 1;
9            else if (nums[i] < nums[i - 1])
10                down = up + 1;
11        }
12
13        return (nums.size() == 0) ? 0 : max(up, down);
14    }
15};