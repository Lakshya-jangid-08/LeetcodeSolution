// Last updated: 7/26/2026, 4:39:47 PM
1class Solution {
2public:
3    vector<vector<int>> permuteUnique(vector<int>& nums) {
4        int n = nums.size();
5        sort(nums.begin(), nums.end());
6        vector<int> vis(n, 0);
7        vector<int> vec;
8        vector<vector<int>> res;
9
10        auto solve = [&](auto &&self, int idx) {
11            vec.push_back(nums[idx]);
12            vis[idx] = 1;
13           
14            if(vec.size() == n) {
15                res.push_back(vec);
16                vis[idx] = 0;
17                vec.pop_back();
18                return;
19            }
20
21            for(int i = 0; i < n; i++) {
22                if (i > 0 && nums[i] == nums[i - 1] && !vis[i - 1]) continue;
23                if(vis[i]) continue;
24                self(self, i);
25            }
26           
27            vis[idx] = 0;
28            vec.pop_back();
29        };
30
31        for(int i = 0; i < n; i++) {
32            if (i > 0 && nums[i] == nums[i - 1]) continue; 
33            solve(solve, i);
34        }
35        return res;
36    }
37};