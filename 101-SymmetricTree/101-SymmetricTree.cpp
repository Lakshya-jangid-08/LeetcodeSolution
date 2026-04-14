// Last updated: 4/14/2026, 4:11:54 PM
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
13
14    bool solve(TreeNode* left, TreeNode*right) {
15        if(left == nullptr && right == nullptr) return true;
16        if(left == nullptr || right == nullptr) return false;
17        if(left->val != right->val) return false;
18        return (solve(left->left, right->right) && solve(left->right, right->left));
19    }
20
21public:
22    bool isSymmetric(TreeNode* root) {
23        if(root == nullptr) return true;
24        return solve(root->left, root->right);
25    }
26};