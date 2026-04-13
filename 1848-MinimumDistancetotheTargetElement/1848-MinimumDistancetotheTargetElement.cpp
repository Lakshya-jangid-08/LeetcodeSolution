// Last updated: 14/4/2026, 12:51:17 am
1class Solution {
2public:
3    int getMinDistance(vector<int>& nums, int target, int start) {
4        int res = nums.size();
5        for (int i = 0; i < nums.size(); ++i) {
6            if (nums[i] == target) {
7                res = min(res, abs(i - start));
8            }
9        }
10        return res;
11    }
12};