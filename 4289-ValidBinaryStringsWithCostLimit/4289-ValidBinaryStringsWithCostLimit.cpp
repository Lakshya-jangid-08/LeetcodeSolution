// Last updated: 6/29/2026, 10:19:22 AM
class Solution {

    void solve(vector<string> & res, string s, int len, int cost, char prev) {
        if(cost < 0) return;
        if(s.length() == len) {
            res.push_back(s);
            return;
        }
        
        solve(res, s + '0', len, cost, '0');
        if(prev != '1') {
            int currCost = s.length();
            solve(res, s + '1', len, cost - currCost, '1');
        }
        return;
    }
    
public:
    vector<string> generateValidStrings(int n, int k) {
        // if cost hai greater than half 
        // like => size hai 5 => 5+1/2 => 3
        vector<string> res;
        string s = "";
        solve(res, s, n, k, '_');
        return res;
    }
};