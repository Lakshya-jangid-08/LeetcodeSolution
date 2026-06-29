// Last updated: 6/29/2026, 10:22:31 AM
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        vector<bool> vis(n);

        const auto dfs = [&](auto &&self, int node) {
            if(vis[node]) return;
            vis[node] = true;
            for(int i = 0; i < n; i++) {
                if(isConnected[node][i])
                    self(self, i);
            }
            return;

        };

        int island = 0;
        for(int i = 0; i < n; i++) {
            if(vis[i]) continue;
            island++;
            dfs(dfs,i);
        }
        return island;
    }
};