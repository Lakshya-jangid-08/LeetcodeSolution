// Last updated: 4/15/2026, 2:43:25 PM
1class Solution {
2public:
3    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
4        sort(nums.begin(), nums.end());
5        vector<vector<int>> res;
6        set<vector<int>> s;
7        res.push_back({});
8
9        int n = nums.size();
10
11        for(int mask = 1; mask < (1 << n); mask++) {
12            vector<int> temp;
13            for(int idx = 0; idx < n; idx++) {
14                if(mask & (1 << idx)) {
15                    temp.push_back(nums[idx]);
16                }
17            }
18            if(s.find(temp) != s.end()) continue;
19            s.insert(temp);
20            res.push_back(temp); 
21        }
22
23        return res;
24    }
25};