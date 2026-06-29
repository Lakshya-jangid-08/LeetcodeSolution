// Last updated: 6/29/2026, 10:22:34 AM
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int l = -1, r = 0;
        int ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 1) {
                r = i;
            }
            else {
                l = i;
            }
            ans = max(ans,r-l);
        }
        return ans;
    }
};