// Last updated: 8/22/2026, 2:15:26 PM
1class Solution {
2
3    int res = 0;
4    pair<int, int> solve(TreeNode* root) {
5        if(!root) return {0 ,0};
6
7        auto L = solve(root->left);
8        auto R = solve(root->right);
9
10        int l = 1 + L.second;
11        int r = 1 + R.first;
12        res = max({res, l, r});
13
14        return {l , r};
15    }
16
17public:
18    int longestZigZag(TreeNode* root) {
19        auto [l, r] = solve(root);        
20        return res - 1;
21    }
22};