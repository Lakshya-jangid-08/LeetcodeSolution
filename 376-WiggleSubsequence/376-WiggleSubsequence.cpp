// Last updated: 8/15/2026, 7:04:29 PM
1class Solution {
2public:
3    vector<int> nextGreaterIndex(vector<int>& nums) {
4        int n = nums.size();
5        vector<int> nge(n, n);
6        stack<int> st; // stores indices
7
8        for (int i = n - 1; i >= 0; i--) {
9            while (!st.empty() && nums[st.top()] <= nums[i]) {
10                st.pop();
11            }
12
13            if (!st.empty())
14                nge[i] = st.top();
15
16            st.push(i);
17        }
18
19        return nge;
20    }
21    vector<int> nextSmallerIndex(vector<int>& nums) {
22        int n = nums.size();
23        vector<int> nse(n, n);
24        stack<int> st; // stores indices
25
26        for (int i = n - 1; i >= 0; i--) {
27            while (!st.empty() && nums[st.top()] >= nums[i]) {
28                st.pop();
29            }
30
31            if (!st.empty())
32                nse[i] = st.top();
33
34            st.push(i);
35        }
36
37        return nse;
38    }
39
40
41    int wiggleMaxLength(vector<int>& nums) {
42        int n = nums.size();
43        vector<vector<int>> dp(n, vector<int>(2, -1));
44
45        vector<int> nge = nextGreaterIndex(nums);
46        vector<int> nse = nextSmallerIndex(nums);
47
48        const auto solve = [&](auto &&self, int idx, int isUp) -> int {
49            if(idx == n) return 0;
50
51            int &res = dp[idx][isUp];
52            if(res != -1) return res;
53
54            res = 0;
55            if(isUp) {
56                int nextIdx = nge[idx];
57                while(nextIdx < n) {
58                    res = max(res, 1 + self(self, nextIdx, 0));
59                    nextIdx = nge[nextIdx];
60                }
61            } else {
62                int nextIdx = nse[idx];
63                while(nextIdx < n) {
64                    res = max(res, 1 + self(self, nextIdx, 1));
65                    nextIdx = nse[nextIdx];
66                }
67            }
68            return res;
69        };
70
71        int res = 0;
72        for(int i = 0; i < n; i++) {
73            int a = 1 + solve(solve, i, 1);
74            int b = 1 + solve(solve, i, 0);
75            res = max({res, a, b});
76        }
77        return res;
78    }
79};