// Last updated: 6/29/2026, 10:20:23 AM
class Solution {
public:
    string processStr(string s) {
        
        string res = "";

        for(auto &c : s) {
            if(c == '#') {
                if(res.length() == 0) continue;
                res += res;
            } else if(c == '%') {
                if(res.length() == 0) continue;
                reverse(res.begin(), res.end());
            } else if(c == '*') {
                if(res.length() == 0) continue;
                res.pop_back();
            } else {
                res.push_back(c);
            }
        }

        return res;
    }
};