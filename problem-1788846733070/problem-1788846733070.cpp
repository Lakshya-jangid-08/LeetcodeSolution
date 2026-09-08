// Last updated: 9/8/2026, 11:22:13 AM
1class Solution {
2public:
3    long long subArrayRanges(vector<int>& nums) {
4        long long sum = 0;
5        int n = nums.size();
6
7        for(int l = 0; l < n; l++) {
8            int mnv = nums[l], mxv = nums[l];
9            for(int r = l; r < n; r++) {
10                mxv = max(mxv, nums[r]);
11                mnv = min(mnv, nums[r]);
12
13                sum += 1LL * (mxv - mnv);
14            }
15        }
16        return sum;
17    }
18};