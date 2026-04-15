// Last updated: 4/15/2026, 10:03:17 AM
1class Solution {
2public:
3    int closestTarget(vector<string>& words, string target, int startIndex) {
4        
5        int n = words.size();
6        int ans = INT_MAX;
7        for(int i = startIndex; i < (startIndex + n); i++) {
8            if(words[(i) % n] == target) {
9                ans = min(ans, i - startIndex);
10            }
11        }
12        for(int i = startIndex; i > (startIndex - n  -1); i--) {
13            if(words[(i + n) % n] == target) {
14                ans = min(ans, startIndex - i);
15            }
16        }
17        return (ans == INT_MAX ? -1 : ans);
18    }
19};