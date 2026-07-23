// Last updated: 7/24/2026, 12:29:07 AM
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
14    vector<int> rightSideView(TreeNode* root) {
15        vector<int> res;
16        if(!root) return res;
17        queue<TreeNode*> q;
18        q.push(root);
19        int lvl = 0;
20        while(!q.empty()) {
21            int len = q.size();
22            while(len--) {
23                auto node = q.front(); q.pop();
24                if(len == 0) res.push_back(node->val);
25                if(node->left) q.push(node->left);
26                if(node->right) q.push(node->right);
27            }
28            lvl += 1;
29        }
30        return res;
31    }
32};