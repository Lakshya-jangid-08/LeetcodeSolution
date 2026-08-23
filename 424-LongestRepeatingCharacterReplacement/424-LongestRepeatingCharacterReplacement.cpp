// Last updated: 8/23/2026, 11:39:07 PM
1class Solution {
2public:
3    int characterReplacement(string s, int k) {
4        int n = s.length();
5        int len = 0;
6        for(int i = 0; i < 26; i++) {
7            int l = 0, r = 0;
8            int count = 0;
9            char allow = 'A' + i;
10            while(r < n) {
11                count += (s[r] != allow);
12                while(count > k) {
13                    count -= (s[l] != allow);
14                    l++;
15                }
16                len = max(len, r - l + 1);
17                r++;
18            }
19        }
20        return len;
21    }
22};