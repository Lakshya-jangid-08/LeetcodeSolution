// Last updated: 6/29/2026, 10:23:50 AM
class Solution {
public:
    int longestValidParentheses(string s) {
        int cnt = 0;
        int len = 0;
        int left = -1;

        for(int i = 0; i < s.length(); i++) {
            if(cnt < 0) {
                left = i - 1; 
                cnt = 0;
            }
            
            if(s[i] == ')') cnt--;
            else  cnt++;

            if(cnt == 0) {
                len = max(len, i - left);
            } 
        }

        int right = s.length();
        cnt = 0;
        for(int i = s.length() - 1; i >= 0; i--) {
            if(cnt < 0) {
                right = i + 1; 
                cnt = 0;
            }

            if(s[i] == ')') cnt++;
            else  cnt--;

            if(cnt == 0) {
                len = max(len, right - i);
            }
        }

        return len;
    }
};