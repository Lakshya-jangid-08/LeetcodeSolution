// Last updated: 6/29/2026, 10:20:06 AM
class Solution {
    unordered_map<int, unordered_map<int, int>> dp;
public:

    int solve(vector<int> & nums, int idx, int curr, int target) {
        if(idx == nums.size()){
            if(curr == target) return 0;
            else return -1e7;
        }
        if(dp[idx].count(curr)) return dp[idx][curr];

        // taake
        int take = 1 + solve(nums, idx + 1, curr ^ nums[idx], target);
        int skip = solve(nums, idx + 1, curr, target);

        return dp[idx][curr] = max(take , skip);
    }
    
    int minRemovals(vector<int>& nums, int target) {
        int res = solve(nums, 0, 0, target);
        return (res <= -1e4 ? -1 : nums.size() - res);
    }
};