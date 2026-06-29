// Last updated: 6/29/2026, 10:22:45 AM
class Solution {
public:
    int longestSubstring(string s, int k) {
        int ans = 0;
        for(int len = k; len <= s.length(); len++) {
            int freq[26] = {0};
            int r = 0, l = 0;
            for(r = 0; r < len; r++) {
                freq[s[r] - 'a']++;
            }
            int minFreq = 1e9;
            for(auto val : freq) {
                if(!val) continue;
                minFreq = min(val, minFreq);
            }
            if(minFreq >= k) {
                ans = len;
                continue;
            }
            while(r < s.length()) {
                freq[s[r] - 'a']++;
                freq[s[l] - 'a']--;
                l++; r++;
                int minFreq = 1e9;
                for(auto val : freq) {
                    if(!val) continue;
                    minFreq = min(val, minFreq);
                }
                if(minFreq >= k) {
                    ans = len;
                    break;
                }
            }
        }
        return ans;
    }
};