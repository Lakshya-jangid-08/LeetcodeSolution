// Last updated: 8/27/2026, 11:07:13 PM
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
14    pair<int, int> solve(TreeNode* root) {
15        if(!root) {
16            // no path sum so inf, and one line sum is also 0
17            return {-1e8, -1e8};
18        }
19
20        auto [l_linearSum, l_pathSum] = solve(root->left);
21        auto [r_linearSum, r_pathSum] = solve(root->right);
22
23        return {
24            max({l_linearSum + root->val, r_linearSum + root->val, root->val}),
25            max({ 
26                l_linearSum + root->val + r_linearSum,
27                r_pathSum,
28                l_pathSum,
29                l_linearSum,
30                r_linearSum
31            })
32        };
33    }
34
35    int maxPathSum(TreeNode* root) {
36        auto [linearSum, pathSum] = solve(root);
37        return max(linearSum, pathSum);
38    }
39};