// Last updated: 6/4/2026, 11:54:02 pm
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
14    TreeNode* insertIntoBST(TreeNode*  root, int val) {
15        if(root == nullptr){
16            return new TreeNode(val);
17        }
18        if(val < root->val)  {
19            root-> left = insertIntoBST(root-> left,val);
20        }
21        else {
22            root->right = insertIntoBST(root -> right, val);
23        }
24            return root;
25    }
26};