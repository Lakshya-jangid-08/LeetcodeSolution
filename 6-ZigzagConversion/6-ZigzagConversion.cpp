// Last updated: 4/23/2026, 5:32:47 PM
1class Solution {
2public:
3    string convert(string s, int numRows) {
4        if(numRows == 1) return s;
5        vector<string> strs(numRows + 1, "");
6        int idx = 0;
7        int inc = 0;
8        for(int i = 0; i < s.length(); i++) {
9            strs[idx].push_back(s[i]);
10            if(idx == numRows - 1) inc = -1;
11            if(idx == 0) inc = 1;
12            idx += inc;
13        }
14        for(int i = 1; i < numRows; i++) {
15            strs[0] += strs[i];
16        }
17        return strs[0];
18    }
19};