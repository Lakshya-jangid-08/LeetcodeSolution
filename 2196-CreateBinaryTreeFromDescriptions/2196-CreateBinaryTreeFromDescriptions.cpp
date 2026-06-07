// Last updated: 6/7/2026, 10:26:29 AM
1class Solution {
2public:
3    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
4        unordered_map<int, TreeNode*> nodeMp;
5        set<int> childSet;
6
7        for (auto& it : descriptions) {
8            int par = it[0], child = it[1], isLeft = it[2];
9
10            if (!nodeMp.count(par))
11                nodeMp[par] = new TreeNode(par);
12
13            if (!nodeMp.count(child))
14                nodeMp[child] = new TreeNode(child);
15
16            TreeNode* node = nodeMp[par];
17
18            if (isLeft)
19                node->left = nodeMp[child];
20            else
21                node->right = nodeMp[child];
22
23            childSet.insert(child);
24        }
25
26        for (auto child : childSet) {
27            nodeMp.erase(child);
28        }
29
30        return nodeMp.begin()->second;
31    }
32};