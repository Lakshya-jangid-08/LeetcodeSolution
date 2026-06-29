// Last updated: 6/29/2026, 10:20:16 AM
class Solution {
public:
    int MOD = 1e9 + 7;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        for(auto &q : queries) {
            auto l = q[0], r = q[1], k = q[2], v = q[3];
            int idx = l;
            while(idx <= r) {
                nums[idx] = (1LL* nums[idx] * v) % MOD;
                idx += k;
            }
        }
        int res = 0;
        for(auto &num : nums) {
            res = res ^ num;
        }
        return res;
    }
};