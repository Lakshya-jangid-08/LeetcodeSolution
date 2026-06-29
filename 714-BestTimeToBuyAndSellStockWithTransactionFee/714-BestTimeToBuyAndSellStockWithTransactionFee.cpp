// Last updated: 6/29/2026, 10:22:24 AM
class Solution {
    int solve(vector<int> &nums, int fee, int idx, int sell, int dp[][2]) {

        if(nums.size() == idx) return 0;
        if(dp[idx][sell] != -1) return dp[idx][sell];
        
        int optionA = 0;
        if(sell) {
            optionA = solve(nums, fee, idx + 1, !sell, dp) - nums[idx];
        } else {
            optionA = solve(nums, fee, idx + 1, !sell, dp) + nums[idx] - fee;
        }
        int optionB = solve(nums, fee, idx + 1, sell, dp);
        return dp[idx][sell] = max(optionA, optionB);
    }
public:
    int maxProfit(vector<int>& prices,int fee) {
        int n = prices.size();
        int dp[n][2];

        memset(dp, -1, sizeof(dp));
        return solve(prices, fee, 0, 1, dp);
    }
};