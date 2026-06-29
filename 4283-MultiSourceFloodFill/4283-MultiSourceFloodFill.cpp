// Last updated: 6/29/2026, 10:19:26 AM
class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        queue<pair<int, int>> q;

        vector<vector<int>> res(n, vector<int>(m, -1));
        vector<vector<int>> dist(n, vector<int>(m, -1));
        int dx[]= {-1, 1, 0, 0};
        int dy[]= {0, 0, -1, 1};

        for(auto &s : sources) {
            int x = s[0], y = s[1], w = s[2];
            q.push({x,y});
            res[x][y] = w;
            dist[x][y] = 0;
        }

        int step = 0;
        while(!q.empty()) {
            int len = q.size();
            step++;
            while(len--) {
                
                auto [x,y] = q.front(); q.pop();
                int w = res[x][y];

                for(int i = 0; i < 4; i++) {
                    
                    int u = dx[i] + x;
                    int v = dy[i] + y;

                    if(u < 0 || v < 0 || u >= n || v >= m) continue;

                    if(dist[u][v] == -1) {
                        dist[u][v] = step;
                        res[u][v] = w;
                        q.push({u, v});
                    } else if(dist[u][v] == step) {
                        res[u][v] = max(res[u][v], w);
                    }

                }

            }
        }
        return res;
    }
};