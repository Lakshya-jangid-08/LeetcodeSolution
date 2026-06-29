// Last updated: 6/29/2026, 10:22:59 AM
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        set<long long> s;

        int r = 0, l = 0;

        while(r < nums.size()) {
            auto it = s.lower_bound(nums[r] - valueDiff);
            if(it != s.end() && abs(1LL * nums[r] - 1LL * *it) <= valueDiff) return true;

            s.insert(nums[r]);
            if(r - l >= indexDiff) {
                s.erase(nums[l]);
                l++;
            }
            r++;
        }
        return false;
    }
};