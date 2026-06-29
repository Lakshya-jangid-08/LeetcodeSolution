// Last updated: 6/29/2026, 10:19:43 AM
class Solution {
public:
    int longestBalanced(string s) {
        unordered_map<int, pair<int, int>> mp;

        int ones = 0, zeros = 0;
        for(auto c : s) {
            if(c=='0') zeros++;
            else ones++;
        }
        if(ones == zeros) return s.length();
        if(ones == 0 || zeros == 0) return 0;

        mp[0] = {-1, -2};
        int curr = 0, maxlen = 0;
        for(int i = 0; i < s.length(); i++) {
            curr += (s[i] == '0' ? - 1 : 1);

            if(mp.count(curr)) {
                maxlen = max(maxlen, i - mp[curr].first);
            }

            int t1 = curr - 2; // means 2 extra 1's need to replace with one 0's
            if(mp.count(t1)) {
                int width  = i - mp[t1].first;
                int currZero = (width - 2) / 2;
                if(currZero < zeros) {
                    maxlen = max(maxlen, width);
                }
                else if(mp[t1].second != -2) {
                    maxlen = max(maxlen, i - mp[t1].second);
                }
            }
            int t2 = curr + 2; // opppo;
            if(mp.count(t2)) {
                int width  = i - mp[t2].first;
                int currOne = (width - 2) / 2;
                if(currOne < ones) {
                    maxlen = max(maxlen, width);
                }
                else if(mp[t2].second != -2) {
                    maxlen = max(maxlen, i - mp[t2].second);
                }
            }


            if(mp.count(curr) == 0) {
                mp[curr] = {i, -2};
            } else if(mp[curr].second == -2) {
                mp[curr].second = i;
            }
            
        }
        return maxlen;
        
    }
};