// Last updated: 7/26/2026, 4:11:11 PM
1class Solution {
2public:
3    int totalNQueens(int n) {
4        int res = 0;
5        vector<string> cb(n, string(n, '.')); // chessBoard
6
7        const auto checkCol = [&](int row, int col) -> bool {
8            row -= 1;
9            while(row >= 0) {
10                if(cb[row][col] == 'Q') return false;
11                row--;
12            }
13            return true;
14        }; 
15        
16        const auto checkDiagonal = [&](int row, int col) -> bool {
17            int i = 1;
18            row--;
19            while(row >= 0) {
20                if(col + i < n && cb[row][col + i] == 'Q') return false;
21                if(col - i >= 0 && cb[row][col - i] == 'Q') return false;
22                row--;i++;
23            }
24            return true;
25        };
26
27        const auto solve = [&](auto &&self, int row) -> void {
28            if(row == n) {
29                res += 1;
30                return;
31            }
32            for(int col = 0; col < n; col++) {
33                cb[row][col] = 'Q';
34                bool ok = checkDiagonal(row, col) && checkCol(row, col);
35                if(ok) self(self, row + 1);
36                cb[row][col] = '.';
37            }
38        };
39
40        solve(solve, 0);
41        return res;
42    }
43};