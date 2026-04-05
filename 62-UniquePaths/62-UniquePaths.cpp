// Last updated: 5/4/2026, 10:32:21 pm
1class Solution {
2public:
3    int uniquePaths(int m, int n) {
4        int left = 0;
5        vector<int> up(n, 1);
6        vector<int> curr(n, 0);
7        for(int i = 1; i < m; i++) {
8            for(int j = 0; j < n; j++) {
9                curr[j] = left + up[j]; 
10                left = curr[j];
11            }
12            left = 0;
13            up = curr;
14        }
15        return up[n-1];
16    }
17};