// Last updated: 9/8/2026, 11:14:17 AM
1class Solution {
2public:
3    int subarraysDivByK(vector<int>& nums, int k) {
4        vector<int> mp(k, 0);
5        mp[0]++;
6        int sum = 0, res = 0;
7
8        for(int i = 0; i < nums.size(); i++) {
9            sum = (sum + nums[i] % k + k) % k;
10            res += mp[sum];
11            mp[sum]++;
12        }
13
14        return res;
15    }
16};