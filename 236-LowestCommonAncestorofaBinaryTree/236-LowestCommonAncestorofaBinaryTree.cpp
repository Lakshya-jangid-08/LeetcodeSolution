// Last updated: 7/22/2026, 12:14:35 AM
1class Solution {
2public:
3    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
4        if (!root || root == p || root == q)
5            return root;
6
7        TreeNode* leftSubtree = lowestCommonAncestor(root->left, p, q);
8        TreeNode* rightSubtree = lowestCommonAncestor(root->right, p, q);
9
10        if (leftSubtree && rightSubtree)
11            return root;
12
13        if (leftSubtree)
14            return leftSubtree;
15
16        if (rightSubtree)
17            return rightSubtree;
18
19        return NULL;
20    }
21};