// Last updated: 6/29/2026, 10:21:05 AM
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> nodeMp;
        set<int> childSet;

        for (auto& it : descriptions) {
            int par = it[0], child = it[1], isLeft = it[2];

            if (!nodeMp.count(par))
                nodeMp[par] = new TreeNode(par);

            if (!nodeMp.count(child))
                nodeMp[child] = new TreeNode(child);

            TreeNode* node = nodeMp[par];

            if (isLeft)
                node->left = nodeMp[child];
            else
                node->right = nodeMp[child];

            childSet.insert(child);
        }

        for (auto child : childSet) {
            nodeMp.erase(child);
        }

        return nodeMp.begin()->second;
    }
};