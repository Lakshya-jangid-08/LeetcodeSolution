// Last updated: 6/9/2026, 12:12:07 PM
1class Solution {
2public:
3    int minMoves(vector<int>& nums, int limit) {
4        int n = nums.size();
5        vector<int> diff(2 * limit + 2, 0);
6
7        for(int i = 0; i < n/ 2; i++) {
8            int a = min(nums[i], nums[n - i - 1]);
9            int b = max(nums[i], nums[n - i - 1]);
10
11            diff[2] += 2;
12            diff[a + 1] -= 1;
13            diff[b + limit + 1]  += 1;
14            diff[a + b] -= 1;
15            diff[a + b + 1] += 1;
16        }
17
18        int res = 1e9;
19        for(int sum = 2; sum <= 2 * limit; sum++) {
20            diff[sum] += diff[sum - 1];
21            res = min(res, diff[sum]);
22        }
23        return res;
24    }
25};