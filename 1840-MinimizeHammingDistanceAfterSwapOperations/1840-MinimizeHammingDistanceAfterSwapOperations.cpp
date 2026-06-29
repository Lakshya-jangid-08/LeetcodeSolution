// Last updated: 6/29/2026, 10:21:31 AM
class Solution {
public:
    int minimumHammingDistance(vector<int>& src, vector<int>& dst, vector<vector<int>>& as) {
        int n = src.size();
        vector<int> parent(n), rank(n, 0);
        iota(parent.begin(), parent.end(), 0);

        const auto find = [&](auto && self, int x) -> int {
            if(parent[x] == x) return x;
            return parent[x] = self(self, parent[x]);
        };

        const auto unite = [&](int u, int v) {
            int pu = find(find, u);
            int pv = find(find, v);

            if(pu == pv) return;

            if(rank[pu] < rank[pv]) {
                rank[pv] += rank[pu];
                parent[pu] = pv;
            } else {
                rank[pu] += rank[pv];
                parent[pv] = pu;
            }
            return;
        };

        for(auto &it : as) {
            unite(it[0], it[1]);
        }

        unordered_map<int , unordered_map<int, int>> IdxMP;

        for(int i = 0; i < n; i++) {
            int p = find(find, i);
            IdxMP[p][src[i]]++;
        }

        int res = 0;

        for(int i = 0; i < n; i++) {
            int f = find(find, i);
            if(IdxMP[f].count(dst[i]) == 0) {
                res++;
                continue;
            }
            IdxMP[f][dst[i]]--;
            if(IdxMP[f][dst[i]] == 0) {
                IdxMP[f].erase(dst[i]);
            }
        }

        return res;
    }
};