// Last updated: 6/29/2026, 10:22:32 AM
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int dia = 0;

    int height(TreeNode* root) {
        if(root == nullptr) return 0;
        
        int left = height(root->left);
        int right = height(root->right);

        dia = max(dia, left + right);

        return max(left, right) + 1;
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return dia;
    }
};