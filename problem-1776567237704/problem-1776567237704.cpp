// Last updated: 4/19/2026, 8:23:57 AM
1class Solution {
2public:
3    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
4        vector<vector<int>> res(n, vector<int>(m, 0));
5
6        queue<vector<int>> q;
7        vector<vector<int>> visit(n, vector<int>(m, -1));
8
9        for(auto &s : sources) {
10            q.push(s);
11            res[s[0]][s[1]] = s[2];
12            visit[s[0]][s[1]] = 0;
13        }
14        int dx[]= {-1, 1, 0, 0};
15        int dy[]= {0, 0, -1, 1};
16        int step = 0;
17        while(!q.empty()) {
18            int len = q.size();
19            step++;
20            while(len--) {
21                auto s = q.front(); q.pop();
22                int x = s[0], y = s[1];
23                int w = res[x][y];
24
25                for(int i = 0; i < 4; i++) {
26
27                    int u = x + dx[i], v = y + dy[i];
28                    if(u < 0 || v < 0 || u >= n || v >= m) continue;
29
30                    if(visit[u][v] == -1) {
31                        visit[u][v] = step;
32                        res[u][v] = w;
33                        q.push({u, v, w});
34                    } else if (visit[u][v] == step) {
35                        res[u][v] = max(res[u][v], w);
36                    }
37
38                }                
39            }
40        }
41        return res;
42    }
43};