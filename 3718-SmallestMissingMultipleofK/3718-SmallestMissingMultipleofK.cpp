// Last updated: 8/25/2026, 10:14:20 AM
1class Solution {
2public:
3    int missingMultiple(vector<int>& nums, int k) {
4        unordered_set<int> seen(nums.begin(), nums.end());
5        int ans = k;
6        while (seen.count(ans)) {
7            ans += k;
8        }
9        return ans;
10    }
11};