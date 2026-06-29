// Last updated: 6/29/2026, 10:20:37 AM
class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> lowerIdx(26, -1);

        int idx = 0;
        for(auto &c : word) {
            if(c <= 'z' && c >= 'a') lowerIdx[c - 'a'] = idx;
            idx++;
        }

        idx = 0;
        int cnt = 0;
        for(auto &c : word) {
            if(c >= 'A' && c <= 'Z' && lowerIdx[c - 'A'] != -1) {
                if(lowerIdx[c - 'A'] < idx) cnt++;
                lowerIdx[c - 'A'] = -1;
            }
            idx++;
        }

        return cnt;
    }
};