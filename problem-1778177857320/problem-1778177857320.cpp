// Last updated: 5/7/2026, 11:47:37 PM
1class Solution {
2public:
3    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
4        int m = box.size();
5        int n = box[0].size();
6        vector<vector<char>> result(n, vector<char>(m));
7
8        // Create the transpose of the input grid in `result`
9        for (int i = 0; i < n; i++) {
10            for (int j = 0; j < m; j++) {
11                result[i][j] = box[j][i];
12            }
13        }
14
15        // Reverse each row in the transpose grid to complete the 90° rotation
16        for (int i = 0; i < n; i++) {
17            reverse(result[i].begin(), result[i].end());
18        }
19
20        // Apply gravity to let stones fall to the lowest possible empty cell in
21        // each column
22        for (int j = 0; j < m; j++) {
23            // Process each cell in column `j` from bottom to top
24            for (int i = n - 1; i >= 0; i--) {
25                if (result[i][j] == '.') {  // Found an empty cell; check if a
26                                            // stone can fall into it
27                    int nextRowWithStone = -1;
28
29                    // Look for a stone directly above the empty cell
30                    // `result[i][j]`
31                    for (int k = i - 1; k >= 0; k--) {
32                        if (result[k][j] == '*')
33                            break;  // Obstacle blocks any stones above
34                        if (result[k][j] ==
35                            '#') {  // Stone found with no obstacles in between
36                            nextRowWithStone = k;
37                            break;
38                        }
39                    }
40
41                    // If a stone was found above, let it fall into the empty
42                    // cell `result[i][j]`
43                    if (nextRowWithStone != -1) {
44                        result[nextRowWithStone][j] = '.';
45                        result[i][j] = '#';
46                    }
47                }
48            }
49        }
50        return result;
51    }
52};