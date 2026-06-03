// Last updated: 6/3/2026, 5:00:01 PM
1class Solution {
2public:
3
4    int solve(vector<int>& a1, vector<int>& a2, vector<int>& b1, vector<int> &b2) {
5        
6        int finish = 1e9;
7
8        for(int i = 0; i < a1.size(); i++) {
9            finish = min(finish, a1[i] + a2[i]);
10        }
11
12        int res = 1e9;
13        for(int i = 0; i < b1.size(); i++) {
14            res = min(
15                res ,
16                max(finish, b1[i]) + b2[i]
17            );
18        }
19        return res;
20    }
21
22    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
23        // I have two options 
24        // land-water
25        // water-land
26        int res1 = solve(landStartTime, landDuration, waterStartTime, waterDuration);
27        int res2 = solve(waterStartTime, waterDuration, landStartTime, landDuration);
28        return min(res1, res2);
29    }
30};