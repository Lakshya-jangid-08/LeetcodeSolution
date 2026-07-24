// Last updated: 7/24/2026, 2:41:37 PM
1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
8 * };
9 */
10class Codec {
11public:
12    int idx;
13
14    void solve(TreeNode* &root, string &s) {
15        if (!root) {
16            s += "#,";
17            return;
18        }
19
20        s += to_string(root->val);
21        s.push_back(',');
22
23        solve(root->left, s);
24        solve(root->right, s);
25    }
26
27    string serialize(TreeNode* &root) {
28        string res;
29        solve(root, res);
30        return res;
31    }
32
33    void construct(string &s, TreeNode* &root) {
34        if (idx >= s.size()) return;
35
36        string cur = "";
37        while (idx < s.size() && s[idx] != ',') {
38            cur += s[idx];
39            idx++;
40        }
41        idx++; // skip ','
42
43        if (cur == "#") {
44            root = nullptr;
45            return;
46        }
47
48        root = new TreeNode(stoi(cur));
49
50        construct(s, root->left);
51        construct(s, root->right);
52    }
53
54    TreeNode* deserialize(string data) {
55        idx = 0;
56        TreeNode* root = nullptr;
57        construct(data, root);
58        return root;
59    }
60};