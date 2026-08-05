// Last updated: 8/5/2026, 5:11:00 PM
1class Solution {
2public:
3    int lengthOfLongestSubstring(string s) {
4        vector<int> lastSeen(128, -1);
5        int l = 0, r = 0;
6        int ans = 0;
7        for(int r = 0; r < s.length(); r++) {
8            int ls = lastSeen[s[r]];
9            l = max(l, ls + 1);
10
11            lastSeen[s[r]] = r;
12            ans = max(r - l + 1, ans);
13        }
14        return ans;
15    }
16};