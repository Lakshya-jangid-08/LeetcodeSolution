// Last updated: 8/21/2026, 11:45:55 AM
1class Solution {
2    void solve(vector<int> &nums, vector<vector<int>> &ans, int idx, int count, int currSum) {
3        if(idx >= nums.size()) {
4            ans[count].push_back(currSum);
5            return; 
6        }
7
8        solve(nums, ans, idx + 1, count + 1, nums[idx] + currSum);
9        solve(nums, ans, idx + 1, count, currSum);
10        
11        return;
12    }
13
14public:
15    int minimumDifference(vector<int>& nums) {
16        int n = nums.size() / 2;
17        int sum = accumulate(nums.begin(), nums.end(), 0);
18
19        vector<int> L(n), R(n);
20
21        for(int i = 0; i < nums.size(); i++) {
22            if(i < n) {
23                L[i] = nums[i];
24            } else {
25                R[i - n] = nums[i]; 
26            }
27        } 
28
29        vector<vector<int>> left(n + 1), right(n + 1);
30
31        solve(L, left, 0, 0, 0);
32        solve(R, right, 0, 0, 0);
33
34        int diff = 1e8;
35
36        for(int i = 0; i < n; i++) {
37            sort(right[i].begin(), right[i].end());
38        }
39
40        for(int count = 0; count <= n; count++) {
41            for(auto &currSum : left[count]) {
42                int requireCount = n - count;
43                int requireSum = sum/2 - currSum;
44
45                auto &arr = right[requireCount];
46                auto idx = lower_bound(arr.begin(), arr.end(), requireSum) - arr.begin();
47                
48                if(idx > 0) {
49                    diff = min(diff, abs( sum - 2 * (currSum + arr[idx - 1]) ) );
50                } 
51                if(idx < arr.size()) {
52                    diff = min(diff, abs(sum - 2 * (currSum + arr[idx]) ) );
53                }
54            }
55        }
56
57        return diff;
58    }
59};