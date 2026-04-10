// Last updated: 10/4/2026, 3:36:41 pm
1class Solution {
2public:
3    int minimumDistance(vector<int>& arr) {
4        vector<pair<int,int>> nums;
5        int i = 0;
6        for(auto &it : arr) {
7            nums.push_back({it, i++});
8        }
9
10        sort(nums.begin(), nums.end(), [&](auto &a, auto &b) {
11            if(a.first == b.first) return a.second < b.second;
12            return a.first < b.first;
13        });
14
15        int r = 2;
16        int res = 1e9;
17
18        while(r < nums.size()) {
19            if(nums[r].first == nums[r - 2].first) {
20                res = min(res, abs(nums[r].second - nums[r - 2].second) + 
21                        abs(nums[r].second - nums[r - 1].second) + 
22                            abs(nums[r - 1].second - nums[r - 2].second));
23            }
24            r++;
25        }
26        return (res == 1e9 ? -1 : res);
27    }
28};