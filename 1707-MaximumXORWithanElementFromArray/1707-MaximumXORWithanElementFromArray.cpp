// Last updated: 8/20/2026, 6:53:52 PM
1class TreeAncestor {
2public:
3    vector<vector<int>> parent;
4    int row, col;
5    TreeAncestor(int n, vector<int>& anc) {
6        row = n;
7        col = log2(n) + 1;
8
9        parent.resize(n, vector<int>(col, -1));
10
11        for(int node = 0; node < n; node++) {
12            parent[node][0] = anc[node];
13        }
14
15        for(int k = 1; k < col; k++) {
16            for(int node = 0; node < n; node++) {
17                if(parent[node][k - 1] != -1) {  
18                    parent[node][k] = parent[parent[node][k - 1]][k - 1];
19                }
20            }
21        }
22    }
23    
24    int getKthAncestor(int node, int k) {
25        // k -= 1;
26
27        for(int i = col - 1; i >= 0; i--) {
28            if(k & (1 << i)) {
29                node = parent[node][i];
30            }
31            if(node == -1) break;
32        }
33        
34        return node;
35
36    }
37};
38
39/**
40 * Your TreeAncestor object will be instantiated and called as such:
41 * TreeAncestor* obj = new TreeAncestor(n, parent);
42 * int param_1 = obj->getKthAncestor(node,k);
43 */