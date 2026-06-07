// Last updated: 6/7/2026, 3:28:15 PM
1class Solution {
2
3    void solve(vector<string> & res, string s, int len, int cost, char prev) {
4        if(cost < 0) return;
5        if(s.length() == len) {
6            res.push_back(s);
7            return;
8        }
9        
10        solve(res, s + '0', len, cost, '0');
11        if(prev != '1') {
12            int currCost = s.length();
13            solve(res, s + '1', len, cost - currCost, '1');
14        }
15        return;
16    }
17    
18public:
19    vector<string> generateValidStrings(int n, int k) {
20        // if cost hai greater than half 
21        // like => size hai 5 => 5+1/2 => 3
22        vector<string> res;
23        string s = "";
24        solve(res, s, n, k, '_');
25        return res;
26    }
27};