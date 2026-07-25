// Last updated: 7/25/2026, 9:39:10 AM
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
14    TreeNode* deleteNode(TreeNode* &root, int key) {
15        if(!root) return root;
16        if(root->val == key) {
17            auto rightSubTree = root->right;
18            if(!rightSubTree) return root->left;
19            auto temp = root->right;
20            while(temp && temp->left) {
21                temp = temp->left;
22            }
23            if(root->left)
24                temp->left = root->left;
25            root = rightSubTree;
26            return root;
27        }
28        else if(root->val > key) 
29            root->left = deleteNode(root->left, key);
30        else if(root->val < key) 
31            root->right = deleteNode(root->right, key);
32        return root;
33    }
34};