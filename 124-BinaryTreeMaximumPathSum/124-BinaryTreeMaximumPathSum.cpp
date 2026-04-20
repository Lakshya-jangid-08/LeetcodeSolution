// Last updated: 4/20/2026, 7:30:58 PM
1class Solution {
2public:
3    int ans = INT_MIN;
4
5    int helper(TreeNode* node) {
6        if (!node) return 0;
7        int left = max(helper(node->left), 0);
8        int right = max(helper(node->right), 0);
9        ans = max(ans, node->val + left + right);
10        return node->val + max(left, right);
11    }
12
13    int maxPathSum(TreeNode* root) {
14        helper(root);
15        return ans;
16    }
17};