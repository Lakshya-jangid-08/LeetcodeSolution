// Last updated: 6/29/2026, 10:21:43 AM
class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int cnt = 1;
        vector<string> res;
        for(int i = 0; i < target.size(); i++) {
            while(cnt != target[i]) {
                res.push_back("Push");
                res.push_back("Pop");
                cnt++;
            } 
            res.push_back("Push");
            cnt++;
        }
        return res;

    }
};