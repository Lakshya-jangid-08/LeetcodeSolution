// Last updated: 6/29/2026, 10:19:14 AM
class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> res(m);
        for(int i = 0; i < m; i++) {
            string s(n, '#');
            res[i] = s;
            res[i][0] = '.';
        }
        for(int i = 0; i < n; i++) {
            res[m-1][i] = '.';
        }
        return res;
    }
};