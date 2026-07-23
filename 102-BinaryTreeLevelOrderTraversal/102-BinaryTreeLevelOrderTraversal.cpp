// Last updated: 7/23/2026, 4:33:30 PM
1class Solution {
2public:
3    vector<vector<int>> levelOrder(TreeNode* root) {
4        vector<vector<int>> ans;
5
6        if (root == nullptr)
7            return ans;
8
9        queue<TreeNode*> q;
10        q.push(root);
11
12        while (!q.empty()) {
13            int sz = q.size();
14            vector<int> level;
15
16            while (sz--) {
17                TreeNode* node = q.front();
18                q.pop();
19                level.push_back(node->val);
20                if (node->left)
21                    q.push(node->left);
22
23                if (node->right)
24                    q.push(node->right);
25            }
26            ans.push_back(level);
27        }
28        return ans;
29    }
30};