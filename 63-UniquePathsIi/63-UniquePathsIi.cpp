// Last updated: 6/29/2026, 10:23:39 AM
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<int> curr(n), prev(n, 0);

        curr[0] = (obstacleGrid[0][0] == 0) ? 1 : 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0 && j == 0) continue;
                int up  = 0, left = 0;

                if(i - 1 >= 0) up = prev[j];
                if(j - 1 >= 0) left = curr[j-1];
                
                if(obstacleGrid[i][j] == 0)
                    curr[j] = up + left;
                else curr[j] = 0;
            }
            prev = curr;
        }
        return prev[n - 1];
    }
};