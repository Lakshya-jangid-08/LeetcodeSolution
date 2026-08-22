// Last updated: 8/22/2026, 4:13:59 PM
1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
8 * };
9 */
10
11class BinaryLifting {
12    // ancestor arr
13    unordered_map< TreeNode*, vector<TreeNode*> > parent;
14    unordered_map< TreeNode*, int> depth;
15
16    int col;
17
18 public:
19    BinaryLifting(int n) {
20        col = log2(n) + 1;
21    }
22
23    void build(TreeNode* root, TreeNode* par = nullptr, int d = 0) {
24        if(!root) return;
25
26        parent[root].resize(col, nullptr);
27        parent[root][0] = par;
28        depth[root] = d;
29
30        build(root->left, root, d + 1);
31        build(root->right, root, d + 1);
32        return;
33    }
34
35    void build() {
36        for(int i = 1; i < col; i++) {
37            for(auto &[node, ancestor] : parent) {
38                auto mid = ancestor[i - 1];
39                if(mid)
40                    ancestor[i] = parent[mid][i-1];
41            }
42        }
43    }
44
45    TreeNode* findKthAncestor(int k, TreeNode* node) {
46        for(int i = 0; i < col; i++) {
47            if(k & (1 << i)) {
48                node = parent[node][i];
49            }
50            if(!node) return nullptr;
51        }
52        return node;
53    }
54
55    void makeDepthEqual(auto &u, auto &v) {
56        int ud = depth[u], vd = depth[v];
57        if(ud == vd) return;
58
59        if(ud < vd) {
60            swap(vd, ud);
61            swap(u, v);
62        }   
63        int diff = ud - vd;
64        // make equal
65        u = findKthAncestor(diff, u);
66        return;
67    }
68
69    TreeNode* commonAncestor(TreeNode* p, TreeNode* q) {
70        if (p == q)
71            return p;
72
73        for(int i = col - 1; i >= 0; i--) {
74            if(parent[p][i] != parent[q][i]) {
75                p = parent[p][i];
76                q = parent[q][i];
77            }
78        }
79        return parent[p][0];
80    }
81
82};
83
84class Solution {
85public:
86    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
87        BinaryLifting* tree = new BinaryLifting(1e5 + 1);
88        tree->build(root);
89        tree->build();
90
91        tree->makeDepthEqual(p, q);
92        root = tree->commonAncestor(p, q);
93        delete tree;
94        return root;
95    }
96};