// Last updated: 8/6/2026, 1:19:40 PM
1class Solution {
2public:
3    Node* cloneGraph(Node* node) {
4        if (!node) return nullptr;
5
6        unordered_map<Node*, Node*> mp;
7
8        auto solve = [&](auto&& self, Node* n, Node*& r) -> void {
9            if(mp.count(n)) {
10                r = mp[n];
11                return;
12            }
13
14            r = new Node(n->val);
15            mp[n] = r;
16
17            for (Node* x : n->neighbors) {
18                Node* child = nullptr;
19                r->neighbors.push_back(child);
20                self(self, x, r->neighbors.back());
21            }
22        };
23
24        Node* res = nullptr;
25        solve(solve, node, res);
26        return res;
27    }
28};