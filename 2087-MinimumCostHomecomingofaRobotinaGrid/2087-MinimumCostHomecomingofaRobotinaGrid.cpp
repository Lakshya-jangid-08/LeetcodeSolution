// Last updated: 7/29/2026, 10:10:55 PM
1class Solution {
2public:
3    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
4        int ans = 0;
5        
6        while(startPos[0] < homePos[0]) {
7            ans += rowCosts[++startPos[0]];
8        }
9        while(startPos[0] > homePos[0]) {
10            ans += rowCosts[--startPos[0]];
11        }
12
13        while(startPos[1] < homePos[1]) {
14            ans += colCosts[++startPos[1]];
15        }
16        while(startPos[1] > homePos[1]) {
17            ans += colCosts[--startPos[1]];
18        }
19
20        return ans;
21    }
22};