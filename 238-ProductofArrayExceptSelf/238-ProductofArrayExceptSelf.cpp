// Last updated: 8/11/2026, 8:26:26 PM
1class Solution {
2public:
3    vector<int> productExceptSelf(vector<int>& nums) {
4        int n = nums.size();
5        vector<int> prefix(n, 1), suffix(n, 1);
6        prefix[0] = nums[0]; suffix[n - 1] = nums[n - 1];
7        for(int i = 1; i < n; i++) {
8            prefix[i] = prefix[i - 1] * nums[i];
9        }
10        for(int i = n - 2; i >= 0; i--) {
11            suffix[i] = suffix[i + 1] * nums[i]; 
12        }
13        vector<int> res(n, 0);
14        for(int i = 0; i < n; i++) {
15            int left = (i > 0) ? prefix[i - 1] : 1;
16            int right = (i + 1 < n) ? suffix[i + 1] : 1;
17            res[i] = left * right;
18        }
19        return res;
20    }
21};