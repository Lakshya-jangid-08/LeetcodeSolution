// Last updated: 11/4/2026, 12:41:13 am
1class Solution {
2public:
3    int characterReplacement(string s, int k) {
4        int freq[26] = {0};
5    
6        int r = 0, l = 0;
7        int ans = 0;
8        while(r < s.length()) {
9            freq[s[r] - 'A']++;
10            int maxFreq = *max_element(freq, freq + 26);
11            int totalElem = r - l + 1;
12            while(totalElem - maxFreq > k) {
13                freq[s[l] - 'A']--;
14                maxFreq = *max_element(freq, freq + 26);
15                totalElem--;
16                l++;
17            }
18            ans = max(ans, r - l + 1);
19            r++;
20        }
21        return ans;
22    }
23};