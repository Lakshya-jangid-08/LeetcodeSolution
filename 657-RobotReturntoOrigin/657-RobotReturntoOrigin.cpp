// Last updated: 5/4/2026, 7:02:39 pm
1class Solution {
2public:
3    bool judgeCircle(string moves) {
4        int x = 0;
5        int y = 0;
6
7        for(auto &c : moves) {
8            if(c == 'U') x -= 1;
9            if(c == 'D') x += 1;
10            if(c == 'L') y -= 1;
11            if(c == 'R') y += 1;
12        }
13        return (x == 0) && (y == 0);
14    }
15};