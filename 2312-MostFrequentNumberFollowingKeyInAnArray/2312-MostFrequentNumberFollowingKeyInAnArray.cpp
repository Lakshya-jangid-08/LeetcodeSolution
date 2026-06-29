// Last updated: 6/29/2026, 10:21:04 AM
class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        unordered_map<int, int> mp;
        int n = nums.size();

        int mx = 0, res = -1;

        for(int i = 0; i < n - 1; i++) {
            if(nums[i] == key) {
                mp[nums[i + 1]]++;

                if(mp[nums[i + 1]] > mx) {
                    mx = mp[nums[i + 1]];
                    res = nums[i + 1];
                }
            }
        }

        return res;
    }
};