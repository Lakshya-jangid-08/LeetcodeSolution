// Last updated: 8/21/2026, 1:36:47 PM
1class Solution {
2public:
3    int findContentChildren(vector<int>& g, vector<int>& s) {
4        int n = g.size();
5        int m = s.size();
6        int l = 0, r = 0;
7
8        sort(g.begin(),g.end());
9        sort(s.begin(),s.end());
10
11        while(l < m && r < n){
12            if(g[r] <= s[l]){
13                r++;
14            }
15            l++;
16        }
17        return r;
18    }
19};