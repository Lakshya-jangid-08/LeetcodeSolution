// Last updated: 8/25/2026, 1:31:15 PM
1class Solution {
2public:
3    int openLock(vector<string>& deadends, string target) {
4        string initial = "0000";
5        unordered_set <string> st(deadends.begin(), deadends.end());
6        unordered_map<string, bool> visit;
7        queue<string> q;
8        if(st.find(initial) != st.end()) return -1;
9        q.push(initial);
10        visit[initial] = true;
11        int ops = 0;
12    
13        while(!q.empty()) {
14            int len = q.size();
15            while(len--) {
16                string currPassword = q.front(); q.pop();
17                if(currPassword == target) return ops;
18                for(int i = 0; i < 4; i++) {
19                    for(int num = 0; num <= 2; num += 2) {
20                        string temp = currPassword;
21                        int val = temp[i] - '0';
22                        val = (val + num - 1 + 10) % 10;
23                        temp[i] = val + '0';
24                        
25                        if(st.find(temp) != st.end()) continue;
26                        if(visit[temp]) continue;
27                        visit[temp] = true;
28                        
29                        q.push(temp);
30                    }
31                }
32            }
33            ops += 1;
34        }
35        return -1;
36    }
37};