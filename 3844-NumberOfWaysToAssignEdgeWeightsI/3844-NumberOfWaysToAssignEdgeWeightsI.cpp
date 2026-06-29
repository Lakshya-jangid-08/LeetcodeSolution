// Last updated: 6/29/2026, 10:20:28 AM
class Solution {
    private:int max_depth = 0;
    private:void reachDepth(int root, vector<vector<int>> &adj, int depth) {
        if(adj[root].size() == 0) {
            max_depth = max(max_depth, depth);
            return;
        }

        for(auto node : adj[root]) {
            reachDepth(node, adj, depth + 1);
        }        
        return;
    }
    public:int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size();
        int m = n + 3;
        vector<int> indegree(m, 0);
        vector<vector<int>> adj(m);

        for(auto it : edges) {
            auto par = it[0], child = it[1];

            adj[par].push_back(child);
            indegree[child]++;
        }
        int root = 0;
        for(int i = 1; i < m; i++) {
            if(indegree[i]) continue;
            root = i;
            break;
        }
        reachDepth(root, adj, 0);
        long long result = 1;
        int MOD = 1e9 + 7;
        for(int i = 0; i < max_depth-1; i++) {
            result = (2LL * result);
            result = result % MOD;
        }

        return result;
    }
   

};