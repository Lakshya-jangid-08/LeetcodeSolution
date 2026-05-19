// Last updated: 5/19/2026, 11:29:21 PM
1class Solution {
2public:
3    int getCommon(vector<int>& nums1, vector<int>& nums2) {
4        unordered_map<int, bool> mp;
5
6        for(auto it : nums1) {
7            if(mp.contains(it)) continue;
8            mp[it] = true;
9        }
10        int ans = 1e9 + 7;
11        for(auto it : nums2) {
12            if(mp.contains(it)) ans = min(ans, it);
13        }
14        return (ans == 1e9 + 7 ? -1 : ans);
15    }
16};