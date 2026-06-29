// Last updated: 6/29/2026, 10:22:39 AM
class Solution {
public:
    int compress(vector<char>& chars) {
        
        int cnt = 1;
        int len = 0;
        char prev = chars[0];
        for(int i = 1; i < chars.size(); i++) {
            if(cnt == 1) len++;
            if(prev == chars[i]) {
                chars.erase(chars.begin() + i);
                i--;
                cnt++;
            } else if(cnt != 1){
                int k = 0;
                while(cnt > 0) {
                    int dig = cnt % 10;
                    cnt /= 10;
                    chars.insert(chars.begin() + i, dig + '0');
                    k++;
                    len++;
                }
                i += k;
                cnt = 1;
            }
            prev = chars[i];
        }
        int n = chars.size();
        if(cnt == 1) len++;
        if(cnt != 1) {
            while(cnt > 0) {
                int dig = cnt % 10;
                cnt /= 10;
                chars.insert(chars.begin() + n, dig + '0');
                len++;
            }
        }

        

        return len;
    }
};