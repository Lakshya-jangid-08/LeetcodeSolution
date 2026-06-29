// Last updated: 6/29/2026, 10:20:08 AM
class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        // all subarray 
        // O(1000 * 1000);
        int n = nums.size();

        int res = 0;
        for(int l = 0; l < n; l++) {
            int count = 0;
            int len = 0;
            for(int r = l; r < n; r++) {
                if(nums[r] == target) count++;
                len += 1;
                if(len / 2 < count) res += 1;
            }
        }

        return res;
    }
};