// Last updated: 6/29/2026, 10:23:00 AM
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        for(int i = 0; i <= min(k, (int)nums.size() - 1); i++) {
            if(mp.count(nums[i])) return true;
            mp[nums[i]]++;
        }
        int l = 0;
        for(int i = k + 1; i < nums.size(); i++) {
            mp[nums[l]]--;
            if(mp[nums[l]] == 0) mp.erase(nums[l]);
            l++;
            if(mp.count(nums[i])) return true;
            mp[nums[i]]++;
        }
        return false;
    }
};