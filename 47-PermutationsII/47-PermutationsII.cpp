// Last updated: 7/26/2026, 4:32:45 PM
1class Solution {
2public:
3    vector<vector<int>> permuteUnique(vector<int>& nums) {
4        set<vector<int>> s;
5        int n = nums.size();
6        vector<int> vis(n, 0);
7        vector<int> vec;
8
9        auto solve = [&](auto &&self, int idx) {
10            vec.push_back(nums[idx]);
11            vis[idx] = 1;
12           
13            if(vec.size() == n) {
14                s.insert(vec);
15                vis[idx] = 0;
16                vec.pop_back();
17                return;
18            }
19            for(int i = 0; i < n; i++) {
20                if(vis[i]) continue;
21                self(self, i);
22            }
23           
24            vis[idx] = 0;
25            vec.pop_back();
26        };
27        for(int i = 0; i < n; i++) solve(solve, i);
28        vector<vector<int>> res(s.begin(), s.end());
29
30        return res;
31    }
32};