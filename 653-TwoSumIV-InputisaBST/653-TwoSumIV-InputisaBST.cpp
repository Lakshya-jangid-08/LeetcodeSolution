// Last updated: 4/14/2026, 5:18:42 PM
1class Solution {
2    unordered_set<int> s;
3
4public:
5    bool findTarget(TreeNode* root, int k) {
6        if(root == nullptr) return false;
7
8        if(s.count(k - root->val)) return true;
9
10        s.insert(root->val);
11
12        return findTarget(root->left, k) || findTarget(root->right, k);
13    }
14};