// Last updated: 6/4/2026, 10:41:26 am
1class Solution {
2public:
3    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
4        queue<pair<int, int>> q;
5
6        vector<vector<int>> res(mat.size(), vector<int>(mat[0].size(), -1)); 
7
8        for(int i = 0; i < mat.size(); i++) {
9            for(int j = 0; j < mat[0].size(); j++) {
10                if(mat[i][j]) continue;
11                q.push({i, j});
12                res[i][j] = 0;
13            }
14        }
15        int dx[] = {-1, 1, 0, 0};
16        int dy[] = {0, 0, -1, 1};
17        int dist = 0;
18        while(!q.empty()) {
19            int lvl = q.size();
20            while(lvl--) {
21                auto [x, y] = q.front(); q.pop();
22                for(int i = 0; i < 4; i++) {
23                    int u = x + dx[i];
24                    int v = y + dy[i];
25
26                    if(u < 0 || v < 0) continue;
27                    if(u >= mat.size() || v >= mat[0].size()) continue;
28                    if(res[u][v] != -1) continue;
29                    res[u][v] = dist + 1;
30                    q.push({ u, v});
31                }
32            }
33            dist++;
34        }
35        return res;
36
37    }
38};