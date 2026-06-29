// Last updated: 6/29/2026, 10:20:39 AM
class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        vector<int> parent(n, -1), rank(n, 0), weight(n, -1);
        
        const auto find = [&](auto && self, int node) -> int {
            if(parent[node] == -1) return node;
            return parent[node] = self(self, parent[node]);
        };

        const auto unite = [&](int u, int v, int w) {
            int pu = find(find, u), pv = find(find, v);

            if(pu == pv) {
                weight[pv] = weight[pv] & w;
                return;
            }

            if(rank[pu] < rank[pv]) {
                rank[pv] += rank[pu];
                parent[pu] = pv;
                weight[pv] = weight[pu] & weight[pv] & w;
            } else {
                rank[pu] += rank[pv];
                parent[pv] = pu;
                weight[pu] = weight[pu] & weight[pv] & w;
            }
            return;
        };

        for(auto &e : edges) {
            unite(e[0], e[1], e[2]);
        }

        vector<int> res;
        for(auto &q  : query) {
            int ps = find(find, q[0]) , pd = find(find, q[1]);
            if(ps != pd) res.push_back(-1);
            else res.push_back(weight[ps]);
        }
        return res;
    }
};