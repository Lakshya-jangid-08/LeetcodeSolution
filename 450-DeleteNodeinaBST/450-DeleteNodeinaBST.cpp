// Last updated: 7/25/2026, 9:49:40 AM
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
13    TreeNode * findMin(TreeNode * root){
14        while(root->left!=NULL){
15            root=root->left;
16        }
17        return root;
18    }
19public:
20    TreeNode* deleteNode(TreeNode* root, int key) {
21        if(!root) return nullptr;
22        else if(root->val < key) {
23            root->right = deleteNode(root->right, key);
24        }
25        else if(root->val > key) {
26            root->left = deleteNode(root->left, key);
27        } else {
28            if(!root->left && !root->right) {
29                delete root;
30                return nullptr;
31            } else if(!root->right) {
32                TreeNode* res = root->left;
33                delete root;
34                return res;
35            } else if(!root->left) {
36                TreeNode* res = root->right;
37                delete root;
38                return res;
39            }
40
41            TreeNode* rightMin = findMin(root->right); 
42            root->val = rightMin->val;
43            root->right = deleteNode(root->right, rightMin->val);
44        }
45        return root;
46    }
47};