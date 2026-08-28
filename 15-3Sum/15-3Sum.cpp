// Last updated: 8/28/2026, 11:59:37 PM
1class Solution {
2public:
3    vector<vector<int>> threeSum(vector<int>& nums) {
4        vector<vector<int>> res;
5        int n = nums.size();
6        sort(nums.begin(), nums.end());
7
8        for(int i = 0; i < n - 2; i++) {
9            if(i > 0 && nums[i] == nums[i - 1]) continue;
10            for(int j = i + 1; j < n -1; j++) {
11                if(j > i + 1 && nums[j] == nums[j - 1]) continue;
12                int v = 0 - nums[i] - nums[j];
13                int idx = lower_bound(nums.begin() + j + 1, nums.end(), v) - nums.begin();     
14                if(idx == n || nums[idx] != v)
15                    continue;
16                res.push_back({nums[i], nums[j], nums[idx]});
17            }
18        }
19        
20        return res;
21    }
22};