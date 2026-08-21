// Last updated: 8/22/2026, 12:25:23 AM
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    pair<long long, long long> dfs(TreeNode* node) {
        if (!node) return {0, 0};
        auto L = dfs(node->left);
        auto R = dfs(node->right);
        long long notRob = max(L.first, L.second) + max(R.first, R.second);
        long long rob = node->val + L.first + R.first;
        return {notRob, rob};
    }
    int rob(TreeNode* root) {
        auto res = dfs(root);
        return (int)max(res.first, res.second);
    }
};