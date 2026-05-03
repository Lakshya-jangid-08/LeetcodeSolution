// Last updated: 5/3/2026, 10:55:23 AM
1class Solution {
2public:
3    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {
4        int n = nums.size();
5        vector<int> forward(n), backward(n);
6
7        // closet
8        forward[0] = backward[n-1] = 0;
9        for(int i = 0; i < n-1; i++) {
10            int closet;
11            if(i == 0) {
12                closet = i + 1;
13            } else {
14                closet = (nums[i] - nums[i-1] <= nums[i + 1] - nums[i]) ? i - 1 : i + 1;
15            }
16            forward[i + 1] = (closet > i ? 1 : nums[i + 1] - nums[i]) + forward[i]; 
17        }
18
19        for(int i = n - 1; i > 0; i--) {
20            int closet;
21            if(i == n -1) {
22                closet = i - 1;
23            } else {
24                closet = (nums[i] - nums[i-1] <= nums[i + 1] - nums[i]) ? i - 1 : i + 1;
25            }
26            backward[i - 1] = (closet < i ? 1 : nums[i] - nums[i - 1]) + backward[i];
27        } 
28
29        vector<int> res;
30
31        for(auto &q : queries) {
32            int l = q[0], r = q[1];
33            int val = (l > r ? backward[r] - backward[l] : forward[r] - forward[l]);
34            res.push_back(val); 
35        }
36
37        return res;
38    }
39};