// Last updated: 6/29/2026, 10:21:48 AM
class Solution {
    int getDistance(char a, char b) {
        int p = a - 'A';
        int q = b - 'A';
        int x1 = p / 6, y1 = p % 6;
        int x2 = q / 6, y2 = q % 6;
        return abs(x1 - x2) + abs(y1 - y2);
    }
public:

    int dp[301][26][26];

    int solve(string word, int idx, int f1, int f2) {
        if(word.length() == idx) return 0;

        if(dp[idx][f1][f2]!= -1) return dp[idx][f1][f2];

        int takef1 = getDistance(word[idx], f1 + 'A') + solve(word, idx + 1, word[idx] - 'A', f2);
        int takef2 = getDistance(word[idx], f2 + 'A') + solve(word, idx + 1, f1, word[idx] - 'A');

        return dp[idx][f1][f2] =  min(takef1, takef2);
    }

    int minimumDistance(string word) {
        memset(dp, -1, sizeof(dp));
        int minDis = 1e9;
        for(int i = 0; i < 26; i++) {
            for(int j = 0; j < 26; j++) {
                minDis = min(minDis, solve(word, 0, i, j));
            }
        }
        return minDis;
    }
};