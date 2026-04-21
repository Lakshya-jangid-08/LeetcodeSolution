// Last updated: 4/21/2026, 9:47:31 PM
#pragma GCC optimize("Ofast,unroll-loops")
#include <vector>
#include <numeric>

using namespace std;

static const int fast_io = []() {
    ios_base::sync_with_stdio(0); cin.tie(0); return 0;
}();

class Solution {
    int parent[100005];
    int component_and[100005];

    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }

    void unite(int i, int j, int w) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            parent[root_i] = root_j;
            component_and[root_j] &= component_and[root_i];
        }
        // В любом случае обновляем AND компоненты текущим ребром
        component_and[root_j] &= w;
    }

public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        // Инициализация
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            component_and[i] = (1 << 20) - 1; // Заполняем единицами (макс. вес 10^5 < 2^17)
        }

        for (const auto& e : edges) {
            unite(e[0], e[1], e[2]);
        }

        vector<int> res;
        res.reserve(query.size());

        for (const auto& q : query) {
            int s = q[0], t = q[1];
            int root_s = find(s);
            int root_t = find(t);

            if (root_s != root_t) {
                res.push_back(-1);
            } else {
                res.push_back(component_and[root_s]);
            }
        }

        return res;
    }
};