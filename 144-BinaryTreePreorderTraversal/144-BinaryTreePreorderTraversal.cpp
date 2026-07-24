// Last updated: 7/24/2026, 11:55:28 PM
1class Solution {
2public: // N L R
3    vector<int> preorderTraversal(TreeNode* root) {
4        if(!root) return {};
5        vector<int> res;
6        auto curr = root;
7        
8        while(curr) {
9            if(curr->left) {
10                // right-most node;
11                auto prev = curr->left;
12                while(prev && prev->right && prev->right != curr) {
13                    prev = prev->right;
14                } 
15
16                if(prev->right) {
17                    curr = curr->right;
18                    prev->right = nullptr;
19                } else {
20                    res.push_back(curr->val);
21                    prev->right = curr;
22                    curr = curr->left;
23                }
24
25            } else {
26                res.push_back(curr->val);
27                curr = curr->right;
28            }
29        }
30        return res;
31    }
32};