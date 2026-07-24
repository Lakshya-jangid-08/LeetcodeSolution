// Last updated: 7/24/2026, 9:48:59 PM
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
14    vector<int> inorderTraversal(TreeNode* root) {
15        if(!root) return {};
16        vector<int> res;
17        auto curr = root;
18        // - L N R
19        while(curr) {
20            if(curr->left) {
21                // right-most node;
22                auto prev = curr->left;
23                while(prev && prev->right && prev->right != curr) {
24                    prev = prev->right;
25                } 
26
27                if(prev->right) {
28                    res.push_back(curr->val);
29                    curr = curr->right;
30                    prev->right = nullptr;
31                } else {
32                    prev->right = curr;
33                    curr = curr->left;
34                }
35
36            } else {
37                res.push_back(curr->val);
38                curr = curr->right;
39            }
40        }
41        return res;
42    }
43};