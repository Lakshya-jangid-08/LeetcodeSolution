// Last updated: 8/3/2026, 8:44:47 PM
1class Solution {
2public:
3    string stoneGameIII(vector<int>& stoneValue) {
4        int n = stoneValue.size();
5
6        vector<int> dp(n, -1e8);
7
8        const auto solution = [&](auto &&self, int idx) -> int {
9            if(idx >= n) return 0;
10
11            int &res = dp[idx];
12            if(res != -1e8) return res;
13            int values = 0;
14            for(int inc = 0; inc + idx < n && inc < 3; inc++) {
15                values += stoneValue[idx + inc];
16                res = max(res, values - self(self, idx + inc + 1));
17            }
18            return res;
19        };
20
21        int val = solution(solution, 0);
22        return val > 0 ? "Alice" : (val < 0 ? "Bob" : "Tie"); 
23
24    }
25};