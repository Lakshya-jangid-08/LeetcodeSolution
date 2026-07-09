// Last updated: 7/9/2026, 1:56:09 PM
1class Solution {
2public:
3    vector<int> spiralOrder(vector<vector<int>>& matrix) {
4        
5        int n = matrix.size(), m = matrix[0].size();
6        int spiralLvl = (min(n, m) + 1) / 2;
7
8        vector<int> res;
9
10        for(int i = 0; i < spiralLvl; i += 1) {
11            int maxX = n - 1 - i;
12            int maxY = m - 1 - i;
13            int minX = i;
14            int minY = i;
15
16            if (minX == maxX) {               // single row
17                for (int j = minY; j <= maxY; j++)
18                    res.push_back(matrix[minX][j]);
19                continue;
20            }
21
22            if (minY == maxY) {               // single column
23                for (int i = minX; i <= maxX; i++)
24                    res.push_back(matrix[i][minY]);
25                continue;
26            }
27
28            for(int i = minY; i < maxY; i++) {
29                res.push_back(matrix[minX][i]);
30            }
31            for(int i = minX; i < maxX; i++) {
32                res.push_back(matrix[i][maxY]);
33            }
34            for(int i = maxY; i > minY; i--) {
35                res.push_back(matrix[maxX][i]);
36            }
37            for(int i = maxX; i > minX; i--) {
38                res.push_back(matrix[i][minY]);
39            }
40        }
41        return res;
42    }
43};