// Last updated: 5/15/2026, 9:01:33 PM
1class Solution {
2public:
3    int findMin(vector<int>& nums) {
4        return *partition_point(nums.begin(), nums.end(), [&](int n) { return n > nums.back(); });
5    }
6};