// Last updated: 8/11/2026, 8:19:00 PM
1class Solution {
2public:
3    int maxSubArray(vector<int>& nums) {
4        int sum = 0, res = -1e9;
5        for(const auto & n : nums) {
6            sum += n;
7            res = max(res, sum);
8            if(sum < 0) sum = 0;
9        }
10        return res;
11    }
12};