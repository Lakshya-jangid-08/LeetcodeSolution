// Last updated: 8/21/2026, 1:34:39 PM
1class Solution {
2public:
3    int findContentChildren(vector<int>& g, vector<int>& s) {
4        sort(s.rbegin(), s.rend());
5        sort(g.rbegin(), g.rend());
6
7        int idx1 = 0, idx2 = 0;
8        int count = 0;
9        while(idx1 < s.size()) {
10            while(idx2 < g.size() && g[idx2] > s[idx1]) {
11                idx2++;
12            }
13            if(idx2 == g.size()) return count;
14            count += 1;
15            idx2++;
16            idx1++;
17        }
18        return count;
19    }
20};