// Last updated: 7/24/2026, 12:49:03 AM
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
14    int widthOfBinaryTree(TreeNode* root) {
15        queue<pair<TreeNode*, long long>> q;
16        q.push({root, 0});
17        long long width = 0;
18
19        while(!q.empty()) {
20            int len = q.size();
21            long long mxc = q.back().second, mnc = q.front().second;
22            width = max(width, mxc - mnc + 1); 
23
24            while(len--) {
25                auto [node, col] = q.front(); q.pop();
26                col -= mnc;
27                if(node->left) q.push({node->left, 2 * col + 1});
28                if(node->right) q.push({node->right, 2 * col + 2});
29            }
30        }
31        return width;
32    }
33};