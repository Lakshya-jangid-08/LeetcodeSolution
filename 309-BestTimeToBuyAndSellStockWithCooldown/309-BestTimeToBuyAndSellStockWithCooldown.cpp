// Last updated: 6/29/2026, 10:22:53 AM
class Solution {
    int solve(vector<int> &nums, int idx, int buy, int cd, int dp[][2][2]) {

        if(nums.size() == idx) return 0;
        if(dp[idx][buy][cd] != -1) return dp[idx][buy][cd];
        
        int optionA = 0;
        if(buy) {
            if(cd == 0)
                optionA = solve(nums, idx + 1, !buy, cd, dp) - nums[idx];
        } else {
            optionA = solve(nums, idx + 1, !buy, cd | 1, dp) + nums[idx];
        }
        int optionB = solve(nums, idx + 1, buy, cd & 0, dp);
        return dp[idx][buy][cd] = max(optionA, optionB);
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int dp[n][2][2];

        memset(dp, -1, sizeof(dp));
        return solve(prices, 0, 1, 0,dp);
    }
};