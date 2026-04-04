// Last updated: 4/4/2026, 10:25:38 am
1class Solution {
2public:
3    int lengthOfLongestSubstring(string s) {
4        unordered_map<char, int> mp;
5
6        int l = 0;
7        int len = 0;
8        for(int r = 0; r < s.length(); r++) {
9            mp[s[r]]++;
10            while(mp[s[r]] > 1) {
11                mp[s[l]]--;
12                l++;
13            }
14            len = max(len, r - l + 1);
15        }
16        return len;
17    }
18};