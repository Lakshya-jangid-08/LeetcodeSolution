// Last updated: 6/29/2026, 10:23:10 AM
class Solution {
public:
    int maxProfit(int k, vector<int>& nums) {
        int n = nums.size();   
        int dp[n + 1][2][k + 1];

        memset(dp, 0, sizeof(dp));

        for(int idx = n - 1; idx >= 0; idx--) {
             for(int buy = 1; buy >= 0; buy--) {
                for(int trans = k-1; trans >= 0; trans--) {
                    int profit = 0;
                
                    if(buy) {
                        profit = dp[idx + 1][0][trans] - nums[idx];
                    } else {
                        profit = dp[idx + 1][1][trans + 1] + nums[idx];
                    }
                
                    dp[idx][buy][trans] =  max(profit, dp[idx + 1][buy][trans]);
                
                }
            }
        }

        return dp[0][1][0];

    }
};