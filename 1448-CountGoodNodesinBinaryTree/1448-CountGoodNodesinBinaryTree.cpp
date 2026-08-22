// Last updated: 8/22/2026, 3:11:31 PM
1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
8 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
9 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
10 * };
11 */
12class Solution {
13public:
14    int goodNodes(TreeNode* root) {
15        int count = 0;
16
17        const auto dfs = [&](auto &&self, TreeNode* &node, int mxv) -> void {
18            if(!node) return;
19
20            int v = node->val;
21            mxv = max(mxv, v);
22            
23            if(mxv <= v) count += 1;
24            if(node->left) self(self, node->left, mxv);
25            if(node->right) self(self, node->right, mxv);
26        };
27
28        dfs(dfs, root, root->val);
29        return count;
30    }
31};