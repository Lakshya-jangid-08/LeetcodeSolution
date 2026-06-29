// Last updated: 6/29/2026, 10:23:03 AM
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        int prev1 = 0, prev2 = 0, curr = 0;
        for(int i = n - 2; i >= 0; i--) {
            curr = max(prev1, nums[i] + prev2);
            prev2 = prev1;
            prev1 = curr;
        }   

        int res = curr;
        prev1 = 0; prev2 = 0;
        for(int i = n - 1; i >= 1; i--) {
            curr = max(prev1, nums[i] + prev2);
            prev2 = prev1;
            prev1 = curr;
        }

        return max(res, curr);
    }
};