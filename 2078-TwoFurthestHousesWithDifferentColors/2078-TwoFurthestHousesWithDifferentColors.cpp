// Last updated: 4/20/2026, 9:53:15 AM
1class Solution {
2public:
3    int maxDistance(vector<int>& colors) {
4        int n = colors.size();
5        int ans = -1;
6        for(int i = 0; i < n; i++) {
7            for(int j = 0; j < n; j++) {
8                if(colors[i] != colors[j]) ans = max(ans, abs(i - j));
9            }
10        }
11        return ans;
12    }
13};