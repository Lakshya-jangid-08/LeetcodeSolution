// Last updated: 7/25/2026, 1:45:13 PM
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
13    bool solve(TreeNode* root, long long mnv, long long mxv) {
14        if(!root) return true;
15        int ans = (mnv < 1LL * root->val && mxv > 1LL * root->val);
16        return ans && solve(root->left, mnv, min(1LL * root->val, mxv)) && solve(root->right, max(1LL * root->val, mnv), mxv);
17    }
18public:
19    bool isValidBST(TreeNode* root) {
20        return solve(root, -1e15, 1e15);
21    }
22};