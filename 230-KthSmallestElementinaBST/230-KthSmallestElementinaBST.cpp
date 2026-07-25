// Last updated: 7/25/2026, 1:01:29 PM
1class Solution {
2public:
3    void solve(TreeNode* root, int &cnt, int &ans, int k){
4        if(root == NULL)    return;
5        //left, root, right 
6        solve(root->left, cnt, ans, k);
7        cnt++;
8        if(cnt == k){
9            ans = root->val;
10            return;
11        }
12        solve(root->right, cnt, ans, k);
13    }
14    int kthSmallest(TreeNode* root, int k) {
15        
16        int cnt = 0;        
17        int ans;
18        solve(root, cnt, ans, k);
19        return ans;
20    }
21};