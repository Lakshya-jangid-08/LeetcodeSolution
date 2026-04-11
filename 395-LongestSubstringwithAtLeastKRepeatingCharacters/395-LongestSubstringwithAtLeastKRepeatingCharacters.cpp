// Last updated: 11/4/2026, 2:56:03 pm
1class Solution {
2public:
3    int longestSubstring(string s, int k) {
4        int ans = 0;
5        for(int len = k; len <= s.length(); len++) {
6            int freq[26] = {0};
7            int r = 0, l = 0;
8            for(r = 0; r < len; r++) {
9                freq[s[r] - 'a']++;
10            }
11            int minFreq = 1e9;
12            for(auto val : freq) {
13                if(!val) continue;
14                minFreq = min(val, minFreq);
15            }
16            if(minFreq >= k) {
17                ans = len;
18                continue;
19            }
20            while(r < s.length()) {
21                freq[s[r] - 'a']++;
22                freq[s[l] - 'a']--;
23                l++; r++;
24                int minFreq = 1e9;
25                for(auto val : freq) {
26                    if(!val) continue;
27                    minFreq = min(val, minFreq);
28                }
29                if(minFreq >= k) {
30                    ans = len;
31                    break;
32                }
33            }
34        }
35        return ans;
36    }
37};