// Last updated: 7/25/2026, 1:47:53 PM
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
public:
    bool recursion(TreeNode* root,long long x, long long y){
        if(root==NULL) return true;
        if(root->val <= x || root->val >= y){
            return false;
        }
        return recursion(root->left,x,root->val) && recursion(root->right,root->val,y);
    }
    bool isValidBST(TreeNode* root) {
        return recursion(root,LLONG_MIN,LLONG_MAX);
    }
};