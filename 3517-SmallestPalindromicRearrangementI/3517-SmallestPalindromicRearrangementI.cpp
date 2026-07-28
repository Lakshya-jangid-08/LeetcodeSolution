// Last updated: 7/28/2026, 2:26:37 PM
1class Solution {
2public:
3    string smallestPalindrome(string s) {
4        int n = s.length();
5        int bucket[26] = {0};
6
7        for(int i = 0; i < n / 2; i++) {
8            int c = s[i] - 'a';
9            bucket[c]++;
10        }
11    
12        int idx = 0;
13        for(int i = 0; i < 26; i++) {
14            while(bucket[i] > 0) {
15                s[idx] = s[n - 1 - idx] = i + 'a';
16                bucket[i]--; idx++;
17            }
18        }
19        return s;
20    }
21};