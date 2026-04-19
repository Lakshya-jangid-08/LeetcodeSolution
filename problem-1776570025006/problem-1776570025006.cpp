// Last updated: 4/19/2026, 9:10:25 AM
1class Solution {
2    vector<int> pathIdx; 
3    long long dp[17][2][8][11];
4
5    long long solve(string s, int idx, int tight, int pos, int prev) {
6        if(idx == 16) return (pos == 7);
7
8        if(dp[idx][tight][pos][prev] != -1) return dp[idx][tight][pos][prev];
9
10        int lb = 0;
11        int ub = (tight ? s[idx] - '0' : 9);
12        long long cnt = 0;
13        for(int i = lb; i <= ub; i++) {
14
15            if(pos < 7 && pathIdx[pos] == idx) {
16                if(prev == 10 || i >= prev) {
17                    cnt += solve(s, idx + 1, (tight && i == ub), pos + 1, i);
18                }
19            } else {
20                cnt += solve(s, idx + 1, (tight && i == ub), pos, prev);
21            }
22            
23        }
24        return dp[idx][tight][pos][prev] = cnt;
25    }
26
27    string padding(string &s) {
28        while(s.size() < 16) s = "0" + s;
29        return s;
30    }
31public:
32    long long countGoodIntegersOnPath(long long l, long long r, string directions) {
33
34        vector<vector<int>> matrix(4, vector<int>(4, 0));
35        int x = 0, y = 0;
36
37        pathIdx.push_back(0);
38        for(auto c : directions) {
39            if(c == 'D') {
40                x += 1;
41            } else {
42                y += 1;
43            }
44            pathIdx.push_back(x * 4 + y);
45        } 
46
47        memset(dp, -1, sizeof(dp));
48        string left = to_string(l - 1);
49        left = padding(left);
50        // dp =? idx,  tight, pos, prev
51        long long val1 = solve(left, 0, 1, 0, 10);
52
53        
54        memset(dp, -1, sizeof(dp));
55        string right = to_string(r);
56        right = padding(right);
57        long long val2 = solve(right, 0, 1, 0, 10);
58        // cout << val1 << " " << val2;
59        return val2 - val1;
60    }
61};