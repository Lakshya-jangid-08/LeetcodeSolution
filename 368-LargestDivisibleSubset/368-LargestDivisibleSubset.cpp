// Last updated: 6/29/2026, 10:22:49 AM
class Solution {
    vector<vector<int>> dp;
    vector<int> res;
    void solve(vector<int> &nums, int idx, int prevIdx, vector<int> &temp) {
        if(idx == nums.size()) {
            res = (res.size() < temp.size()) ? temp : res;
            return;
        }

        if(dp[idx][prevIdx] != -1 && dp[idx][prevIdx] >= temp.size()) return;

        if(prevIdx == nums.size() || nums[idx] % nums[prevIdx] == 0) {
            temp.push_back(nums[idx]);
            solve(nums, idx + 1, idx, temp);
            temp.pop_back();
        } 

        solve(nums, idx + 1, prevIdx, temp);

        dp[idx][prevIdx] = temp.size(); 

        return;
   }

public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        dp.resize(n,vector<int>(n + 1, -1));
        vector<int> temp;
        solve(nums, 0, n, temp);
        return res;
    }
};