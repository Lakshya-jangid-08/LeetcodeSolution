// Last updated: 7/23/2026, 6:31:10 PM
1class Solution {
2public:
3    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
4        vector<vector<int>> res;
5        if(root==NULL) return res;
6        queue<TreeNode*> q;
7        q.push(root);
8        bool flag=true;
9        while(!q.empty()){
10            int n=q.size();
11            vector<int> row(n);
12            for(int i=0;i<n;i++){
13                TreeNode* node=q.front();
14                q.pop();
15                int index=(flag) ? i:(n-i-1);
16                row[index]=node->val;
17                if(node->left) q.push(node->left);
18                if(node->right) q.push(node->right);
19            }
20            flag=!flag;
21            res.push_back(row);
22        }
23        return res;
24    }
25};