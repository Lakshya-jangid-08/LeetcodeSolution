// Last updated: 6/29/2026, 10:20:35 AM
class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char, bool> islower;

        for(auto c : word) {
            if('a' <= c && c <= 'z') {
                islower[c] = true;
            }
        }

        int cnt = 0;
        for(auto c : word) {
            if('A' <= c && c <= 'Z' && islower[c+32]) {
                cnt++;
                islower[c+32] = false;
            }
        }

        return cnt;
    }
};