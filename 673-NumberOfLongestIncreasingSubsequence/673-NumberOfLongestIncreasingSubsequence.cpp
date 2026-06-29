// Last updated: 6/29/2026, 10:22:25 AM
class Solution {
    int n;
    vector<pair<int, int>> dp;

    pair<int,int> solve(vector<int> &nums, int idx) {
        
        if(dp[idx].first != -1 && dp[idx].second != -1) return dp[idx];

        int maxCnt = 1;
        int curr = 0;

        for(int i = idx + 1; i < n; i++) {
            if(nums[idx] < nums[i]) {
                auto [len, cnt] = solve(nums, i);
                if(len + 1 > curr) {
                    curr = len + 1;
                    maxCnt = cnt;
                }
                else if(len + 1 == curr) {
                    maxCnt += cnt;
                }
            }
        }
        return dp[idx] = {curr, maxCnt};
    }

public:
    int findNumberOfLIS(vector<int>& nums) {
        n = nums.size();
        int res = 0, maxLen = 0;

        dp.assign(n, {-1, -1});

        for(int i = 0; i < n; i++) {
            auto [len, cnt] = solve(nums, i);
            if(len > maxLen) {
                maxLen = len;
                res = cnt;
            } else if(len == maxLen) {
                res += cnt;
            }
        }
        return res;
    }
};