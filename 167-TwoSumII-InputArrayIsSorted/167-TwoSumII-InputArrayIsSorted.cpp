// Last updated: 7/4/2026, 11:40:18 pm
1class Solution {
2public:
3    vector<int> twoSum(vector<int>& nums, int target) {
4        int n = nums.size();
5        int l = 0;
6        int r = n - 1;
7        while(l < r) {
8            int cur = nums[l] + nums[r];
9            if(cur == target) {
10                return {l + 1, r + 1};
11            } else if(cur > target) {
12                r--;
13                // while(l < r && nums[r] == nums[r + 1]) r--;
14            } else {
15                l++;
16                // while(l < r && nums[l] == nums[l + 1]) l++;
17            }
18        }
19        return {-1, -1};
20    }
21};