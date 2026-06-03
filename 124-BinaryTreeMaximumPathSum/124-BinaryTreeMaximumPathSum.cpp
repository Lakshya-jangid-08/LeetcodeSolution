// Last updated: 6/3/2026, 9:50:48 AM
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
14    int res = -1e9;
15
16    int solve(TreeNode* root) {
17
18        if(!root) return 0;
19
20        int left = solve(root->left);
21        left = max(left, 0);
22        int right = solve(root->right);
23        right = max(right, 0);
24
25        res = max(res, left + root->val + right);
26
27        return max(left, right) + root->val;
28
29    }
30
31    int maxPathSum(TreeNode* root) {
32        if(!root) return 0;
33        solve(root);
34        return res;
35    }
36};