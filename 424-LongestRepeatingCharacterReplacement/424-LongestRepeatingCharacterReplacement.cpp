// Last updated: 11/4/2026, 1:55:59 pm
1class Solution {
2public:
3    int characterReplacement(string s, int k) {
4        int freq[26] = {0};
5        
6        int l = 0, maxFreq = 0, maxLen = 0;
7
8        for (int r = 0; r < s.size(); r++) {
9            freq[s[r] - 'A']++;
10            maxFreq = max(maxFreq, freq[s[r] - 'A']);
11
12            if(r - l + 1 - maxFreq > k) {
13                freq[s[l] - 'A']--;
14                l++;
15            }
16
17            maxLen = max(maxLen, r - l + 1);
18        }
19
20        return maxLen;
21    }
22};