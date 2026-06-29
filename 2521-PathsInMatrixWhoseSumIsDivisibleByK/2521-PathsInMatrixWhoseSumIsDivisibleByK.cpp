// Last updated: 6/29/2026, 10:21:02 AM
class Solution {
    int MOD = 1e9 + 7;
public:

    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> curr(m + 1, vector<int>(51, 0));
        vector<vector<int>> prev(m + 1, vector<int>(51, 0));

        for(int i = n - 1; i >= 0; i--) {
            for(int j = m - 1; j >= 0; j--) {
                for(int x = 0; x < 51; x++) {
                    int currSum = (x + grid[i][j]) % k; 
                    if(i == n-1 && j == m-1) curr[j][x] = (currSum == 0);
                    else {
                        curr[j][x] = (prev[j][currSum] + curr[j + 1][currSum]) % MOD;
                    }
                }
            }  
            prev = curr;
        }

        return prev[0][0];
    }
};