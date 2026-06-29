// Last updated: 6/29/2026, 10:23:17 AM
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        while(l < r) {
            int cur = nums[l] + nums[r];
            if(cur == target) {
                return {l + 1, r + 1};
            } else if(cur > target) {
                r--;
                // while(l < r && nums[r] == nums[r + 1]) r--;
            } else {
                l++;
                // while(l < r && nums[l] == nums[l + 1]) l++;
            }
        }
        return {-1, -1};
    }
};