// Last updated: 4/18/2026, 2:14:40 PM
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        bool balanced = true;
        depth(root, balanced);
        return balanced;
    }

private:
    int depth(TreeNode* node, bool& balanced) {
        if (!node) {
            return 0;
        }

        // Find left tree depth
        int left = depth(node->left, balanced);

        // Find right tree depth
        int right = depth(node->right, balanced);

        if (abs(left - right) > 1) {
            balanced = false;
            return 0;
        } else {
            return std::max(left, right) + 1;
        }
    }
};