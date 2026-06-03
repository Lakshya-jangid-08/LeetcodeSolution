// Last updated: 6/3/2026, 9:50:20 AM
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
14    unordered_map<TreeNode*, int> dp;
15    int res = -1e9;
16
17    int solve(TreeNode* root) {
18
19        if(!root) return 0;
20
21        if(dp.contains(root)) return dp[root];
22
23        int left = solve(root->left);
24        left = max(left, 0);
25        int right = solve(root->right);
26        right = max(right, 0);
27
28        res = max(res, left + root->val + right);
29
30        return dp[root] = max(left, right) + root->val;
31
32    }
33
34    int maxPathSum(TreeNode* root) {
35        if(!root) return 0;
36        solve(root);
37        return res;
38    }
39};