// Last updated: 8/14/2026, 9:22:13 AM
1class Solution {
2public:
3    int maximumLengthSubstring(string s) {
4        int l = 0;
5        int r = 0;
6        vector<int> freq(26);
7        int maxLen = 0;
8        while(r < s.length()) {
9            freq[s[r] - 'a']++;
10            while(freq[s[r] - 'a'] > 2) {
11                freq[s[l] - 'a']--;
12                l++;
13            }
14            maxLen = max(maxLen, r - l + 1);
15            r++;
16        }
17        return maxLen;
18    }
19};