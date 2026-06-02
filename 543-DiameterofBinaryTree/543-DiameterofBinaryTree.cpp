// Last updated: 6/2/2026, 10:02:03 AM
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
13    int dia = 0;
14
15    int height(TreeNode* root) {
16        if(root == nullptr) return 0;
17        
18        int left = height(root->left);
19        int right = height(root->right);
20
21        dia = max(dia, left + right);
22
23        return max(left, right) + 1;
24    }
25
26public:
27    int diameterOfBinaryTree(TreeNode* root) {
28        height(root);
29        return dia;
30    }
31};