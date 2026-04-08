// Last updated: 8/4/2026, 2:15:22 pm
1class Solution {
2public:
3    int MOD = 1e9 + 7;
4    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
5        for(auto &q : queries) {
6            auto l = q[0], r = q[1], k = q[2], v = q[3];
7            int idx = l;
8            while(idx <= r) {
9                nums[idx] = (1LL* nums[idx] * v) % MOD;
10                idx += k;
11            }
12        }
13        int res = 0;
14        for(auto &num : nums) {
15            res = res ^ num;
16        }
17        return res;
18    }
19};