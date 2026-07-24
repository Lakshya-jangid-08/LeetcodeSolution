// Last updated: 7/24/2026, 9:14:23 PM
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
13    void solve(TreeNode* root) {
14        if(!root) return;
15
16        solve(root->left);
17        auto left = root->left;
18        root->left = nullptr;
19
20        auto right = root->right;
21        root->right = left;
22        while(root->right) root = root->right;
23        root->right = right;
24        solve(root->right); 
25    }
26public:
27    void flatten(TreeNode* root) {
28        // add left subtree at - left 
29        solve(root);
30    }
31};