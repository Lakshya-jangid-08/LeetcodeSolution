// Last updated: 7/23/2026, 10:22:10 PM
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
13    map<int, map<int, vector<int>> > mp;
14    void solve(TreeNode* root, int col, int row) {
15        if(!root) return;
16
17        mp[col][row].push_back(root->val);
18        solve(root->left, col - 1, row + 1);
19        solve(root->right, col + 1, row + 1);
20        
21        return;
22    }
23public:
24    vector<vector<int>> verticalTraversal(TreeNode* root) {
25        solve(root, 0, 0);
26        vector<vector<int>> res;
27
28        for(auto &[col, rowMp] : mp) {
29            vector<int> nums;
30            for(auto &[row, vec] : rowMp) {
31                sort(vec.begin(), vec.end());
32                for(auto &v : vec) nums.push_back(v);
33            }
34            res.push_back(nums);
35        }
36
37        return res;
38    }   
39};