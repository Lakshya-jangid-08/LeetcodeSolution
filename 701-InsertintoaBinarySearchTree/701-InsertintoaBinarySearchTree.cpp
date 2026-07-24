// Last updated: 7/25/2026, 12:04:00 AM
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
14    TreeNode* insertIntoBST(TreeNode* &root, int &val) {
15        if(!root) return root = new TreeNode(val);
16        if(root->val > val) 
17            root->left = insertIntoBST(root->left, val);
18        if(root->val < val)
19            root->right = insertIntoBST(root->right, val);
20        return root;
21    }
22};