// Last updated: 6/29/2026, 10:23:07 AM
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        for(auto &pr : prerequisites) {
            int u = pr[0], v = pr[1];
            adj[v].push_back(u);
            indegree[u] += 1;
        }

        queue<int> q;
        int process = 0;
        for(int i = 0; i < numCourses; i++) {
            if(indegree[i]==0) {
                process++;
                q.push(i);
            }
        }
        while(!q.empty()) {
            int root = q.front(); q.pop();
            for(auto &node : adj[root]) {
                indegree[node]--;
                if(indegree[node] == 0) {
                    process++;
                    q.push(node);
                }
            }
        }
        
        return (process == numCourses);
    }
};