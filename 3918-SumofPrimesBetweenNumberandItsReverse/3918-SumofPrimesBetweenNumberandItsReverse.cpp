// Last updated: 5/3/2026, 10:37:10 AM
1class Solution {
2public:
3    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {
4        int n = nums.size();
5        vector<int> closet(n);
6
7        closet[0] = 1;
8        closet[n - 1] = n - 2;
9        for(int i = 1; i < n - 1; i++) {
10            int val1 = abs(nums[i - 1] - nums[i]);
11            int val2 = abs(nums[i + 1] - nums[i]);
12            if(val2 < val1) {
13                closet[i] = i + 1;
14            } else {
15                closet[i] = i - 1;
16            }
17        }
18
19        vector<int> lt(n), rt(n);
20        int prev = 0;
21        for(int i = 0; i < n - 1; i++) {
22            if(closet[i] > i) {
23                lt[i + 1] = 1 + prev;
24            } else {
25                lt[i + 1] = prev + abs(nums[i + 1] - nums[i]);
26            }
27            prev = lt[i + 1];
28        }
29        prev = 0;
30        for(int i = n - 1; i > 0; i--) {
31            if(closet[i] < i) {
32                rt[i - 1] = 1 + prev;
33            } else {
34                rt[i - 1] = prev + abs(nums[i - 1] - nums[i]);
35            }
36            prev = rt[i - 1];
37        }
38
39        vector<int> res;
40        for(auto q : queries) {
41            int l = q[0], r = q[1];
42
43            if(l < r) {
44                int left = lt[l] ;
45                int right = lt[r];
46                // cout << left << "  " << right << endl;
47                res.push_back(right - left);
48            } else {
49                int left =  rt[l];
50                int right = rt[r];
51                res.push_back(right - left);
52            }
53            
54        }
55        
56        return res;
57    }
58};