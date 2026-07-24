// Last updated: 7/24/2026, 12:00:20 PM
1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
8 * };
9 */
10class Solution {
11    unordered_map< TreeNode*, TreeNode*> par;
12
13    void findPar(auto root) {
14        if(!root) return;
15        queue<TreeNode*> tq;
16        tq.push(root);
17        
18        auto insert = [&](auto node, auto parent) -> void {
19            if(!node) return;
20            tq.push(node); par[node] = parent;
21        };
22
23        while(tq.empty() == 0) {
24            auto node = tq.front(); tq.pop();
25            insert(node->left, node);
26            insert(node->right, node);
27        }
28    }
29
30public:
31    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
32        findPar(root);
33
34        unordered_map<TreeNode*, bool> vis;
35        queue<TreeNode*> q;
36        q.push(target);
37        vis[target] = true;
38        int dist = 0;
39
40        auto insert = [&](auto node) -> void {
41            if(!node || vis.count(node)) return;
42            q.push(node); vis[node] = true;
43        };
44
45        while(!q.empty() && dist < k) {
46            int len = q.size();
47            while(len--) {
48                auto node = q.front(); q.pop();
49                insert(node->left);
50                insert(node->right);
51                insert(par[node]);
52            }
53            dist += 1;
54        }
55
56        vector<int> res;
57        while(!q.empty()) {
58            int val = q.front()->val; q.pop();
59            res.push_back(val);
60        }
61        return res;
62    }
63};