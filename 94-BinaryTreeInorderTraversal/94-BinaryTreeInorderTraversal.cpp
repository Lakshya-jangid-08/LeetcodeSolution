// Last updated: 4/15/2026, 10:45:54 PM
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
13    vector<int> res;
14public:
15    vector<int> inorderTraversal(TreeNode* root) {
16        if(!root) return {};
17        inorderTraversal(root->left);
18        res.push_back(root->val);
19        inorderTraversal(root->right);
20        return res;
21    }
22};