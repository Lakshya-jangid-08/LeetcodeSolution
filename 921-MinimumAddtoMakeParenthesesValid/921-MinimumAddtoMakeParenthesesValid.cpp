// Last updated: 9/4/2026, 1:54:12 AM
1class Solution {
2public:
3    int minAddToMakeValid(string s) {
4        int ans = 0, count = 0;
5        for(auto & ch : s) {
6            if(ch == '(')  count++;
7            else count--;
8            if(count < 0) {
9                count = 0;
10                ans += 1;
11            }
12        }   
13        return count + ans;
14    }
15};