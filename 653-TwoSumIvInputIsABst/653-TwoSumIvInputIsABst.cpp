// Last updated: 6/29/2026, 10:22:28 AM
class Solution {
    unordered_set<int> s;

public:
    bool findTarget(TreeNode* root, int k) {
        if(root == nullptr) return false;

        if(s.count(k - root->val)) return true;

        s.insert(root->val);

        return findTarget(root->left, k) || findTarget(root->right, k);
    }
};