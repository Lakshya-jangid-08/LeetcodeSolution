// Last updated: 9/6/2026, 5:49:27 PM
1class Solution {
2public:
3    vector<vector<int>> subsets(vector<int>& nums) {
4        
5        int n = nums.size();
6        vector<vector<int>> res;
7
8        for(int mask = 0; mask < (1 << n); mask++) {
9            res.push_back({});
10            for(int i = 0; i < n; i++) {
11                if(mask & (1 << i))
12                    res.back().push_back(nums[i]);
13            }
14        }
15
16        return res; 
17    }
18};