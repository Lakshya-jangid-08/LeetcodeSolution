// Last updated: 7/26/2026, 4:54:21 PM
1class Solution {
2public:
3    vector<vector<int>> permute(vector<int>& nums) {
4        int n = nums.size();
5        vector<int> vis(n, 0);
6        vector<int> vec;
7        vector<vector<int>> res;
8
9        auto solve = [&](auto &&self, int idx) {
10            vec.push_back(nums[idx]);
11            vis[idx] = 1;
12           
13            if(vec.size() == n) {
14                res.push_back(vec);
15                vis[idx] = 0;
16                vec.pop_back();
17                return;
18            }
19
20            for(int i = 0; i < n; i++) {
21                if(vis[i]) continue;
22                self(self, i);
23            }
24           
25            vis[idx] = 0;
26            vec.pop_back();
27        };
28
29        for(int i = 0; i < n; i++) solve(solve, i);
30        return res;
31    }
32};