// Last updated: 7/25/2026, 1:54:30 PM
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
11class Solution {
12public:
13    TreeNode* lowestCommonAncestor(TreeNode* &root, TreeNode* &p, TreeNode* &q) {
14        if(root == nullptr) return nullptr;
15        if(root->val < p->val && root->val < q->val) {
16            return lowestCommonAncestor(root->right, p, q);
17        } else if(root->val > p->val && root->val > q->val) {
18            return lowestCommonAncestor(root->left, p, q);
19        } else {
20            return root;
21        }
22    }
23};