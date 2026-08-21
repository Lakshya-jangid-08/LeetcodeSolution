// Last updated: 8/22/2026, 12:21:51 AM
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
13    unordered_map<TreeNode*, unordered_map<int, int>> dp;
14    int solve(TreeNode* root, int allow) {
15        if(!root) return 0;
16
17        if(dp[root].count(allow)) return dp[root][allow];
18
19        int take = -1e5;
20        if(allow)   
21            take = root->val + solve(root->left, 0) + solve(root->right, 0);
22        int skip = solve(root->left, 1) + solve(root->right, 1);
23        return dp[root][allow] = max(take, skip);
24    } 
25public:
26    int rob(TreeNode* root) {
27        return solve(root, 1);
28    }
29};