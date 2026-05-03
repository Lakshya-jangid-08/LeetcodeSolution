// Last updated: 5/3/2026, 10:35:58 AM
1class Solution {
2public:
3    vector<int> countOppositeParity(vector<int>& nums) {
4        int n = nums.size();
5        vector<int> res;
6        for (int i = 0; i < n; i++) {
7            int cnt = 0;
8            for (int j = i + 1; j < n; j++) {
9                if (nums[i] % 2 != nums[j] % 2) {
10                    cnt++;
11                }
12            }
13            res.push_back(cnt);
14        }
15        return res;
16    }
17};