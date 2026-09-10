// Last updated: 9/10/2026, 5:31:14 PM
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
13
14public:
15    int res = 0;
16    pair<int, int> solve(TreeNode* root) {
17        if(!root) return {0, 0};
18
19        auto p1 = solve(root->left);
20        auto p2 = solve(root->right);
21
22        int sum = root->val + p1.first + p2.first;
23        int count = 1 + p1.second + p2.second;
24
25        int avg = sum / count;
26        if(avg == root->val) res++;
27
28        return {sum , count};
29    }
30
31    int averageOfSubtree(TreeNode* root) {
32        solve(root);      
33        return res; 
34    }
35};