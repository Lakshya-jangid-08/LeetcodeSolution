// Last updated: 13/4/2026, 12:58:31 am
1class Solution {
2    int getDistance(char a, char b) {
3        int p = a - 'A';
4        int q = b - 'A';
5        int x1 = p / 6, y1 = p % 6;
6        int x2 = q / 6, y2 = q % 6;
7        return abs(x1 - x2) + abs(y1 - y2);
8    }
9public:
10
11    int dp[301][26][26];
12
13    int solve(string word, int idx, int f1, int f2) {
14        if(word.length() == idx) return 0;
15
16        if(dp[idx][f1][f2]!= -1) return dp[idx][f1][f2];
17
18        int takef1 = getDistance(word[idx], f1 + 'A') + solve(word, idx + 1, word[idx] - 'A', f2);
19        int takef2 = getDistance(word[idx], f2 + 'A') + solve(word, idx + 1, f1, word[idx] - 'A');
20
21        return dp[idx][f1][f2] =  min(takef1, takef2);
22    }
23
24    int minimumDistance(string word) {
25        memset(dp, -1, sizeof(dp));
26        int minDis = 1e9;
27        for(int i = 0; i < 26; i++) {
28            for(int j = 0; j < 26; j++) {
29                minDis = min(minDis, solve(word, 0, i, j));
30            }
31        }
32        return minDis;
33    }
34};