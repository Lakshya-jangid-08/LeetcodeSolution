// Last updated: 4/18/2026, 2:13:17 PM
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
14    int isBalanced(TreeNode* root) {
15        if(!root) return 1;
16
17        int l = isBalanced(root->left);
18        if(l == 0) return 0;
19        int r = isBalanced(root->right);
20        if(r == 0) return 0;
21        if(abs(r - l) <= 1) return 1 + max(l,r);
22        return 0;
23    }
24};