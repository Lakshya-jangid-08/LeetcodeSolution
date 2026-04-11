// Last updated: 12/4/2026, 1:51:13 am
1class Solution {
2public:
3    vector<int> dailyTemperatures(vector<int>& temp) {
4        stack<int> s;
5        int n = temp.size();
6        vector<int> res(n, 0);
7        for(int i = n - 1; i >= 0; i--) {
8            while(!s.empty() && temp[s.top()] <= temp[i]) {
9                s.pop();
10            }
11            if(s.empty()) {
12                s.push(i);
13                res[i] = 0;
14            } else {
15                int idx = s.top();
16                s.push(i);
17                res[i] = idx - i;
18            }
19        }
20        return res;
21    }
22};