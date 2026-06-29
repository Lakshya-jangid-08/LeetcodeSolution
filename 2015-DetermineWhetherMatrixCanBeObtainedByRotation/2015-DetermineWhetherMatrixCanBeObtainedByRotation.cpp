// Last updated: 6/29/2026, 10:21:21 AM
class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        int m = mat[0].size();
        
        for(int t = 0; t < 4; t++) {
            vector<vector<int>> A = mat;
            for(int i = 0; i < n / 2; i++) {
                int low = i;
                int high = n - 1 - i;

                int x = low;
                int v = low;
                while(x <= high) {
                    A[x++][low] = mat[high][v++];
                }

                int y = low;
                int u = high;
                while(y <= high) {
                    A[high][y++] = mat[u--][high];
                }

                x = high;
                v = high;
                while(x >= low) {
                    A[x--][high] = mat[low][v--];
                }

                y = high;
                u = low;
                while(y >= low) {
                    A[low][y--] = mat[u++][low];
                }
            }

            mat = A;
            bool ans = true;
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if(target[i][j] != A[i][j]) ans = false;
                }
            }
            if(ans) return true;
        }
        return false;
    }
};