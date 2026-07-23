// Last updated: 7/23/2026, 4:31:44 PM
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
14    vector<int> temp;
15    vector<int> preorderTraversal(TreeNode* root) {
16        if(!root) return temp;
17        temp.push_back(root->val);
18        preorderTraversal(root->left);
19        preorderTraversal(root->right);
20        return temp;
21    }
22};