// Last updated: 8/29/2026, 12:26:14 AM
1class Solution {
2public:
3    int singleNumber(vector<int>& nums) {
4        int res = 0;
5        for(const auto & v : nums) res ^= v;
6        return res;
7    }
8};