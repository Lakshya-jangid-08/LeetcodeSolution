// Last updated: 6/8/2026, 2:43:53 PM
1class Solution {
2
3    struct trieNode {
4        int idx;
5        int child[26];
6
7        trieNode(int i = -1) {
8            idx = i;
9            memset(child, -1, sizeof(child));
10        }
11    };
12
13    vector<trieNode> trie;
14
15    int getNode(int idx) {
16        trie.emplace_back(idx);
17        return trie.size() - 1;
18    }
19
20    void insertTrie(int root, int idx, vector<string>& wc) {
21
22        string word = wc[idx];
23        int n = word.length();
24
25        for(int i = n - 1; i >= 0; i--) {
26            int ch = word[i] - 'a';
27
28            if(trie[root].child[ch] == -1) trie[root].child[ch] = getNode(idx);
29
30            root = trie[root].child[ch];
31
32            int rIdx = trie[root].idx;
33
34            if(wc[rIdx].length() > n ||
35               (wc[rIdx].length() == n && rIdx > idx))
36                trie[root].idx = idx;
37        }
38    }
39
40    int searchTrie(int root, string &word) {
41        int n = word.length();
42
43        int res_idx = trie[root].idx;
44
45        for(int i = n - 1; i >= 0; i--) {
46            int ch_idx = word[i] - 'a';
47
48            if(trie[root].child[ch_idx] == -1)
49                return res_idx;
50
51            root = trie[root].child[ch_idx];
52            res_idx = trie[root].idx;
53        }
54
55        return res_idx;
56    }
57
58public:
59    vector<int> stringIndices(vector<string>& wc, vector<string>& wq) {
60
61        int n = wc.size(), m = wq.size();
62
63        trie.reserve(500000); // optional
64
65        int root = getNode(0);
66
67        for(int i = 0; i < n; i++) {
68            int idx = trie[root].idx;
69
70            if(wc[idx].length() > wc[i].length() || (wc[idx].length() == wc[i].length() && idx > i))
71                trie[root].idx = i;
72
73            insertTrie(root, i, wc);
74        }
75
76        vector<int> res(m);
77
78        for(int i = 0; i < m; i++) {
79            res[i] = searchTrie(root, wq[i]);
80        }
81
82        return res;
83    }
84};