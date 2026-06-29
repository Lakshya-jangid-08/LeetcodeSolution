// Last updated: 6/29/2026, 10:20:03 AM
class DSU {
public:
    vector<int> par;
    vector<int> rank;
    vector<int> sum;

    DSU(int n) {
        par.resize(n);
        rank.resize(n, 0);
        sum.resize(n, 0);
        for (int i = 0; i < n; i++)
            par[i] = i;
    }

    int find(int x) {
        if (par[x] == x)
            return x;

        int p = par[x];
        par[x] = find(par[x]);
        sum[x] = (sum[x] + sum[p]) % 2;

        return par[x];
    }

    int giveVal(int w, int v, int u) { return (sum[v] + w + sum[u]) % 2; }

    void unite(int u, int v, int w) {
        int pu = find(u);
        int pv = find(v);

        if (rank[pu] < rank[pv]) {
            par[pu] = pv;
            sum[pu] = (sum[u] + sum[v] + w) % 2;
        } else {
            par[pv] = pu;
            sum[pv] = (sum[u] + sum[v] + w) % 2;
            if (rank[pu] == rank[pv])
                rank[pu]++;
        }

        return;
    }
};
class Solution {
public:
    int numberOfEdgesAdded(int n, vector<vector<int>>& edges) {
        // if connected

        DSU ds(n);
        int cnt = 0;
        for (auto e : edges) {
            int u = e[0], v = e[1], w = e[2];

            if (ds.find(u) == ds.find(v)) {
                // same hai mtlb ....
                int val = ds.giveVal(w, v, u);
                if (val & 1)
                    continue;
            } else {
                ds.unite(u, v, w);
            }
            cnt++;
        }

        return cnt;
    }
};