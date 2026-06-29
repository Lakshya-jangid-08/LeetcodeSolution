// Last updated: 6/29/2026, 10:21:35 AM
class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> diff(2 * limit + 2, 0);

        for(int i = 0; i < n/ 2; i++) {
            int a = min(nums[i], nums[n - i - 1]);
            int b = max(nums[i], nums[n - i - 1]);

            diff[2] += 2;
            diff[a + 1] -= 1;
            diff[b + limit + 1]  += 1;
            diff[a + b] -= 1;
            diff[a + b + 1] += 1;
        }

        int res = 1e9;
        for(int sum = 2; sum <= 2 * limit; sum++) {
            diff[sum] += diff[sum - 1];
            res = min(res, diff[sum]);
        }
        return res;
    }
};