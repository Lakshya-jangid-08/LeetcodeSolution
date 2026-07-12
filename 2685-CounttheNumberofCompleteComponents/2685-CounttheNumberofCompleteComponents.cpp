// Last updated: 7/12/2026, 8:22:19 AM
1class Solution {
2public:
3    int countCompleteComponents(int n, vector<vector<int>>& edges) {
4        // Adjacency lists for each vertex
5        vector<vector<int>> graph(n);
6
7        // Build adjacency lists from edges
8        for (const auto& edge : edges) {
9            graph[edge[0]].push_back(edge[1]);
10            graph[edge[1]].push_back(edge[0]);
11        }
12
13        int completeCount = 0;
14        unordered_set<int> visited;
15
16        // Process each unvisited vertex
17        for (int vertex = 0; vertex < n; vertex++) {
18            if (visited.count(vertex)) continue;
19
20            // arr[0] = vertices count, arr[1] = total edges count
21            int componentInfo[2] = {0, 0};
22            dfs(vertex, graph, visited, componentInfo);
23
24            // Check if component is complete - edges should be vertices *
25            // (vertices-1)
26            if (componentInfo[0] * (componentInfo[0] - 1) == componentInfo[1]) {
27                completeCount++;
28            }
29        }
30        return completeCount;
31    }
32
33private:
34    void dfs(int curr, vector<vector<int>>& graph, unordered_set<int>& visited,
35             int componentInfo[2]) {
36        visited.insert(curr);
37        componentInfo[0]++;  // Increment vertex count
38        componentInfo[1] +=
39            graph[curr].size();  // Add edges from current vertex
40
41        // Explore unvisited neighbors
42        for (int next : graph[curr]) {
43            if (!visited.count(next)) {
44                dfs(next, graph, visited, componentInfo);
45            }
46        }
47    }
48};