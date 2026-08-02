// Last updated: 8/2/2026, 11:08:07 AM
1class Solution {
2public:
3    bool stoneGame(vector<int>& piles) {
4        int n = piles.size();
5        int sum = accumulate(piles.begin(), piles.end(), 0);
6
7        vector<vector<int>> dp(n, vector<int>(n, -1));
8
9        const auto calcScore = [&](auto &&self, int l, int r) -> int {
10            if(l > r) return 0;
11            int &res = dp[l][r];
12            if(res != -1) return res;
13            int score1 = piles[l] + min(self(self, l + 2, r), self(self, l + 1, r - 1));
14            int score2 = piles[r] + min(self(self, l + 1, r - 1), self(self, l, r - 2));
15
16            return res = max(score1, score2);
17        };
18
19        int AliceScore = calcScore(calcScore, 0, n - 1);
20        return sum - AliceScore < AliceScore;
21    }
22};