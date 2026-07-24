// Last updated: 7/24/2026, 11:38:54 AM
1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
8 * };
9 */
10class Solution {
11    unordered_map<TreeNode*, int> mp;
12    int find (TreeNode* root, TreeNode* target) {
13        if(!root) return -1;
14        if(root == target) {
15            mp[root] = 0;
16            return 0;
17        }
18
19        int l = find(root->left, target);
20        int r = find(root->right, target);
21
22        if(l != -1) {
23            mp[root] = l + 1;
24            l += 1;
25        } else if(r != -1) {
26            mp[root] = r + 1;
27            r += 1;
28        }
29        return max(r, l);
30    }
31public:
32
33    void solve(TreeNode* root, TreeNode* target, int k, vector<int> &res) {
34        if(!root) return;
35
36        int num = -1;
37        if(mp.count(root)) num = mp[root];
38        if(num == k) res.push_back(root->val);
39
40        if(root->left) {
41            if(num != -1 && mp.count(root->left) == 0) mp[root->left] =  num + 1;
42            solve(root->left, target, k, res);
43        }
44        if(root->right) {
45            if(num != -1 && mp.count(root->right) == 0) mp[root->right] =  num + 1;
46            solve(root->right, target, k, res);
47        }
48        return;
49    }
50
51    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
52        find(root, target);
53        vector<int> res;
54        solve(root, target, k, res);
55        return res;      
56    }
57};
58