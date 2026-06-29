// Last updated: 6/29/2026, 10:22:16 AM
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        unordered_map<int, int> mp;
        
        const auto dfs = [&](auto &&self, int root, int curr) -> bool {
            // cout << root << " " <<curr << endl;
            if(mp.count(root)) return (mp[root] == curr);
            mp[root] = curr;
            for(auto &node : graph[root]) {
                if(!self(self, node, !curr)) return false;
            }
            return true;
        };

        int n = graph.size();
        int ans = 1;
        for(int i = 0; i < n; i++) {
            if(!mp.count(i)) {
                ans = ans && dfs(dfs, i, 1);
            }
        }

        return ans;
    }
};