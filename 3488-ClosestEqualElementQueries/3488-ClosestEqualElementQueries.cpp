// Last updated: 4/16/2026, 12:08:59 PM
1class Solution {
2public:
3    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
4        unordered_map<int, vector<int>> mp;
5
6        int n = nums.size();
7        for(int i = 0; i < n; i++) {
8            mp[nums[i]].push_back(i);
9        }
10
11        vector<int> res;
12
13        for(auto &q : queries) {
14            int val = nums[q];
15            vector<int> & temp = mp[val];
16
17            if(temp.size() == 1) {
18                res.push_back(-1);
19                continue;
20            }
21
22            auto it = lower_bound(temp.begin(), temp.end(), q); // >= find
23            int idx = it - temp.begin();
24            int dist = 1e9;
25
26            int m = temp.size();
27
28            int prevIdx = temp[(idx - 1 + m) % m];
29            int nextIdx = temp[(idx + 1) % m];
30
31            int d1 = abs(q - prevIdx);
32            int d2 = abs(q - nextIdx);
33
34            dist = min(dist, min(d1, n - d1));
35            dist = min(dist, min(d2, n - d2));
36
37            res.push_back(dist);
38
39        }
40
41        return res;
42
43    }
44};