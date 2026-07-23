// Last updated: 7/23/2026, 10:26:28 PM
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
13    map<int, map<int, multiset<int>> > mp;
14    void solve(TreeNode* root, int col, int row) {
15        if(!root) return;
16        mp[col][row].insert(root->val);
17        solve(root->left, col - 1, row + 1);
18        solve(root->right, col + 1, row + 1);
19        return;
20    }
21public:
22    vector<vector<int>> verticalTraversal(TreeNode* root) {
23        solve(root, 0, 0);
24        vector<vector<int>> res;
25
26        for(auto &[_, rowMp] : mp) {
27            vector<int> nums;
28            for(auto &[_, ms] : rowMp) {
29                nums.insert(nums.end(), ms.begin(), ms.end());
30            }
31            res.push_back(nums);
32        }
33
34        return res;
35    }   
36};