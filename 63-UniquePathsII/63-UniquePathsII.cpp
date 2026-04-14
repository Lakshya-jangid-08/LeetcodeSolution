// Last updated: 4/14/2026, 3:45:21 PM
1class Solution {
2    int solve(int m, int n, vector<vector<int>>& dp, vector<vector<int>>& obstacleGrid) {
3        if(m < 0 || n < 0 || obstacleGrid[m][n] == 1) return 0;
4        if(m == 0 && n == 0)    return 1;
5        if(dp[m][n] != -1)  return dp[m][n];    
6        return dp[m][n] = solve(m-1,n,dp, obstacleGrid) + solve(m, n-1, dp, obstacleGrid);
7        
8    }
9public:
10    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
11        int m = obstacleGrid.size();
12        int n = obstacleGrid[0].size();
13        vector<vector<int>> dp(m,vector<int>(n,-1));
14        return solve(m-1,n-1,dp, obstacleGrid);
15    }
16};