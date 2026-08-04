// Last updated: 8/4/2026, 2:13:41 PM
1class Solution {
2public:
3    vector<int> findMissingElements(vector<int>& nums) {
4        unordered_set<int> st(nums.begin(), nums.end());
5        int mn = ranges::min(nums);
6        int mx = ranges::max(nums);
7        vector<int> ans;
8        for (int i = mn + 1; i < mx; i++) {
9            if (!st.contains(i)) {
10                ans.push_back(i);
11            }
12        }
13        return ans;
14    }
15};