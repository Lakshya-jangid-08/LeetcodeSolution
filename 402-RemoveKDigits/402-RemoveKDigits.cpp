// Last updated: 6/29/2026, 10:22:43 AM
class Solution {
public:
    string removeKdigits(string num, int k) {
        string res = "";
        for(auto c : num) {
            while(res != "" && res.back() > c && k > 0) {
                res.pop_back();
                k--;
            } 
            if(res.length() == 0 && c == '0') continue;
            res.push_back(c);
        }
        while(res != "" && k > 0) {
            res.pop_back();
            k--;
        }
        return res.length() ? res : "0";
    }
};