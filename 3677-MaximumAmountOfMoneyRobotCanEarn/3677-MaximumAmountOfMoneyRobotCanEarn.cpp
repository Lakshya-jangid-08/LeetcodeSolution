// Last updated: 6/29/2026, 10:20:30 AM
class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int n = coins[0].size();

        vector<vector<int>> prev(n + 1, vector<int>(3, -1e7));

        prev[1][0] = 0;
        prev[1][1] = 0;
        prev[1][2] = 0;

        for(auto &row : coins) {
            // curr 

            for(int j = 1; j <= n; j++) {
                // 0 means no neu.
                prev[j][2] = max({
                    row[j - 1] + prev[j - 1][2],
                    row[j - 1] + prev[j][2],
                    prev[j - 1][1],
                    prev[j][1],
                });
                prev[j][1] = max({
                    row[j - 1] + prev[j - 1][1],
                    row[j - 1] + prev[j][1],
                    prev[j - 1][0],
                    prev[j][0]
                });
                prev[j][0] = max(row[j - 1] + prev[j][0], row[j - 1] + prev[j - 1][0]);

            }

        }
        return prev[n][2];
    }
};