// Last updated: 6/29/2026, 10:21:19 AM
class Solution {
public:

    long long solve(vector<int> &nums, int idx, int even, long long dp[][2]) {
        if(idx == nums.size()) return 0;

        if(dp[idx][even] != -1) return dp[idx][even];

        // take
        long long take = solve(nums,idx + 1, !even, dp);
        if(even) {
            take += 1LL * nums[idx];
        } else {
            take -= 1LL * nums[idx];
        }
        // skip
        long long skip = solve(nums, idx + 1, even, dp);

        return dp[idx][even] = max(take, skip);

    }

    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        long long dp[n][2];

        memset(dp, -1, sizeof(dp));
        return solve(nums, 0, 1, dp);
    }
};