// Last updated: 4/20/2026, 6:44:10 PM
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
13    unordered_map<TreeNode* , int> treeMP;
14    int sum(TreeNode* root) {
15        if(root == nullptr) return 0;
16        
17        if(treeMP.count(root)) return treeMP[root];
18
19        int l = sum(root->left);
20        int r = sum(root->right);
21
22        return treeMP[root] = max(0,root->val + max(l , r));
23
24    }
25
26public:
27    int maxPathSum(TreeNode* root) {
28        if(!root) return -1e4;
29        int sum1= sum(root->left) + root->val + sum(root->right);
30        return max({
31            sum1,
32            maxPathSum(root->left),
33            maxPathSum(root->right)
34        });
35    }
36};