// Last updated: 12/4/2026, 8:02:06 am
1class Solution {
2public:
3    vector<int> findDegrees(vector<vector<int>>& matrix) {
4        vector<int> res;
5
6        for(auto row : matrix) {
7            int cnt = 0;
8            for(auto val : row) {
9                if(val == 0) continue;
10                cnt++;
11            }
12            res.push_back(cnt);
13        }
14        return res;
15    }
16};