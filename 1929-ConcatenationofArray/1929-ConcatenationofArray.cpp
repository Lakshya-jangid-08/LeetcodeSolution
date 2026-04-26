// Last updated: 4/26/2026, 1:29:09 PM
1class Solution {
2public:
3    vector<string> buildArray(vector<int>& target, int n) {
4        int cnt = 1;
5        vector<string> res;
6        for(int i = 0; i < target.size(); i++) {
7            while(cnt != target[i]) {
8                res.push_back("Push");
9                res.push_back("Pop");
10                cnt++;
11            } 
12            res.push_back("Push");
13            cnt++;
14        }
15        return res;
16
17    }
18};