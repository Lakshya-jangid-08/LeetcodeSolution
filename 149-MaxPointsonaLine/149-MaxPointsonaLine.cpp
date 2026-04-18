// Last updated: 4/19/2026, 12:37:20 AM
1class Solution {
2public:
3    int maxPoints(vector<vector<int>>& points) {
4        int n = points.size();
5        int res = 1;
6
7        for(int i = 0; i < n; i++) {
8            auto x = points[i][0], y = points[i][1];
9            unordered_map<string, int> mp;
10            for(int j = 0; j < n; j++) {
11                if(i == j) continue;
12
13                auto u = points[j][0], v = points[j][1];
14                int upper = (y - v);
15                int lower = (x - u);
16                int gcd = __gcd(lower, upper);
17                
18                string slope = to_string(upper / gcd)  + "/" + to_string(lower / gcd);
19
20                mp[slope]++;
21                res = max(res,1 + mp[slope]);
22            }
23        }
24
25        return res;
26    }  
27};