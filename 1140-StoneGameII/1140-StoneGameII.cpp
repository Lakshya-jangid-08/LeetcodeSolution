// Last updated: 8/3/2026, 8:25:09 PM
1class Solution {
2public:
3    int stoneGameII(vector<int>& piles) {
4        vector<int> &suffixSum = piles;
5        int n = piles.size();
6        for(int i = n - 2; i >= 0; i--) {
7            suffixSum[i] += suffixSum[i + 1];
8        }
9
10        vector<vector<int>> dp(n, vector<int>(n, -1));
11        const auto solution = [&](auto && self, int idx, int M) -> int {
12            if(idx + 2 * M >= n) return suffixSum[idx];
13            int &res = dp[idx][M];
14            if(res != -1) return res;
15
16            for(int X = 1; X <= 2 * M; X++) {
17                res = max(res, suffixSum[idx] - self(self, idx + X, max(M, X)));
18            }
19            return res;
20        };
21
22        return solution(solution, 0, 1);
23
24    }
25};