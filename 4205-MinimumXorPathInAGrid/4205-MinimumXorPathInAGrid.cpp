// Last updated: 6/29/2026, 10:19:55 AM
class Solution {

public:
    int minCost(vector<vector<int>>& grid) {
        vector<vector<unordered_set<int>>> dp( grid.size(), vector< unordered_set<int> >(grid[0].size()));
        int n = grid.size();
        int m = grid[0].size();
        dp[n-1][m-1].insert(grid[n-1][m-1]);
        
        for(int i = n - 1; i >= 0; i--) {
            for(int j = m - 1; j >= 0; j--) {
                if(i + 1 < n) 
                for(auto x : dp[i + 1][j]) {
                    dp[i][j].insert( grid[i][j] ^ x );
                }
                if(j + 1 < m)
                for(auto x : dp[i][j + 1]) {
                        dp[i][j].insert(grid[i][j] ^ x);   
                }
            }
        }
        int res = 1e9;
        for(auto x : dp[0][0]) {
            res = min(res, x);
        }
        
        return res;
    }
};