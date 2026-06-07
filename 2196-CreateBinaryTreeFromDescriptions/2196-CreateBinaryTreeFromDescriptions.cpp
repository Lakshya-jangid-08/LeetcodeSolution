// Last updated: 6/7/2026, 9:38:53 AM
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
14    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
15        // search such node , which freq. is 1 
16        // set then as root , let's suppose
17        // 50 is parent of 20 & 80
18        //  i next go for 20 and 80 and then 
19        // its like level order treversal
20        
21        TreeNode* root = new TreeNode();
22        unordered_map< int, vector<pair<int,int>> > mp;
23        unordered_map<int, bool> findRoot;
24        for(int i = 0; i < descriptions.size(); i++) {
25            int par = descriptions[i][0], child = descriptions[i][1], isLeft = descriptions[i][2];
26            mp[par].push_back({child, isLeft});
27            findRoot[par] = true;
28        }
29
30        for(int i = 0; i < descriptions.size(); i++) {
31            int child = descriptions[i][1];
32            findRoot.erase(child);
33        }
34
35        auto it = findRoot.begin();
36        int rootVal = it->first;
37
38        TreeNode* node = root; 
39        node->val = rootVal;
40
41        queue<TreeNode*> q;
42        q.push(node);
43
44        while(!q.empty()) {
45            
46            auto temp = q.front(); q.pop();
47            
48            auto vec = mp[temp->val];
49
50            for(int i = 0; i < vec.size(); i++) {
51                auto [child, isLeft] = vec[i];
52                if(isLeft) {
53                    temp->left = new TreeNode(child);
54                    TreeNode* childNode = temp->left;
55                    q.push(childNode);
56                } else {
57                    temp->right = new TreeNode(child);
58                    TreeNode* childNode = temp->right;
59                    q.push(childNode);
60                }
61            }
62
63        }
64        return root;
65    }
66};