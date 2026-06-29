// Last updated: 6/29/2026, 10:22:42 AM
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if((sum&1) == 1) return false;
        int n = nums.size();
        int targetSum = sum/2;
        vector<vector<bool>> dp(n, vector<bool>(targetSum + 1, false) );
        for(int i = 0; i < n; i++) {
            dp[i][targetSum] = true;
        }
        for(int i = n-2; i >= 0; i--) {
            for(int k = targetSum; k >= 0; k--) {
                bool val;
                if(k + nums[i] > targetSum) val = false;
                else val = dp[i + 1][k + nums[i]];
                dp[i][k] = ( val || dp[i + 1][k]);
            }
        }
        return dp[0][0];
    }
};