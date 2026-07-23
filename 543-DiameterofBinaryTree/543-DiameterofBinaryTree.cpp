// Last updated: 7/23/2026, 4:44:45 PM
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
14    int diameterOfBinaryTree(TreeNode* root) {
15        int dia = 0;
16        const auto helper = [&](auto &&self, auto node) -> int {
17            if(!node) return 0;
18            int l = self(self, node->left);
19            int r = self(self, node->right);
20            dia = max(dia, l + r);
21            return 1 + max(l, r);
22        };
23        helper(helper, root);
24        return dia;
25    }
26};