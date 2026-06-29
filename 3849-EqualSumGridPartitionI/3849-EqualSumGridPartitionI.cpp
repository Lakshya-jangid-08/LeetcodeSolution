// Last updated: 6/29/2026, 10:20:26 AM
class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        long long int total = 0;

        for(auto &row : grid) {
            for(auto &val : row) {
                total += val;
            }
        }
        if(total & 1) return false;
        long long int target = total / 2;

        int n = grid.size(), m = grid[0].size();
        long long int val = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                val += 1LL * grid[i][j];
            }
            if(val == target) return true;
            if(val > target) break;
        }
        val = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                val += 1LL * grid[j][i];
            }
            if(val == target) return true;
            if(val > target) break;
        }
        return false;
    }
};