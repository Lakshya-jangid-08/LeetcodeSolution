// Last updated: 6/29/2026, 10:20:07 AM
class Solution {
    long long dfs(vector<vector<int>> & adj, int node, vector<long long>& bt) {
        if(adj[node].empty()) return 1LL * bt[node];
        
        long long earliest = 1e15, latest = -1e15;
        for(auto &nextNode : adj[node]) {
            bt[nextNode] = dfs(adj, nextNode, bt);
            earliest = min(earliest, 1LL * bt[nextNode]);
            latest = max(latest, 1LL * bt[nextNode]);
        }

        long long ownDuration = latest - earliest + bt[node];
        return latest + ownDuration;
    }
public:
    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {
        vector<vector<int>> adj(n);

        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1];
            adj[u].push_back(v);
        }
        vector<long long> bt(baseTime.begin(), baseTime.end());
        return dfs(adj, 0, bt);
    }
};