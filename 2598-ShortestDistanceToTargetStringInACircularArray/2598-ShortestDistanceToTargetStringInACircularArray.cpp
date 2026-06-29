// Last updated: 6/29/2026, 10:21:00 AM
class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        
        int n = words.size();
        int ans = INT_MAX;
        for(int i = startIndex; i < (startIndex + n); i++) {
            if(words[(i) % n] == target) {
                ans = min(ans, i - startIndex);
            }
        }
        for(int i = startIndex; i > (startIndex - n  -1); i--) {
            if(words[(i + n) % n] == target) {
                ans = min(ans, startIndex - i);
            }
        }
        return (ans == INT_MAX ? -1 : ans);
    }
};