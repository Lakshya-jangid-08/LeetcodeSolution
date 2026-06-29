// Last updated: 6/29/2026, 10:20:58 AM
class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, bool> mp;

        for(auto it : nums1) {
            if(mp.contains(it)) continue;
            mp[it] = true;
        }
        int ans = 1e9 + 7;
        for(auto it : nums2) {
            if(mp.contains(it)) ans = min(ans, it);
        }
        return (ans == 1e9 + 7 ? -1 : ans);
    }
};