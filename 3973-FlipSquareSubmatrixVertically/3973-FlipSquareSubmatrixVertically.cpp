// Last updated: 6/29/2026, 10:20:17 AM
class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        for(int j = y; j < y + k; j++) {
            for(int i = 0; i < (k) / 2; i++) {
                swap(grid[x + i][j], grid[x + k -1 -i][j]);
            }
        }
        return grid;
    }
};