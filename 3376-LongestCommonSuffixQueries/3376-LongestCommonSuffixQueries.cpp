// Last updated: 6/29/2026, 10:20:38 AM
class Solution {

    struct trieNode {
        int idx;
        int child[26];

        trieNode(int i = -1) {
            idx = i;
            memset(child, -1, sizeof(child));
        }
    };

    vector<trieNode> trie;

    int getNode(int idx) {
        trie.emplace_back(idx);
        return trie.size() - 1;
    }

    void insertTrie(int root, int idx, vector<string>& wc) {

        string word = wc[idx];
        int n = word.length();

        for(int i = n - 1; i >= 0; i--) {
            int ch = word[i] - 'a';

            if(trie[root].child[ch] == -1) trie[root].child[ch] = getNode(idx);

            root = trie[root].child[ch];

            int rIdx = trie[root].idx;

            if(wc[rIdx].length() > n ||
               (wc[rIdx].length() == n && rIdx > idx))
                trie[root].idx = idx;
        }
    }

    int searchTrie(int root, string &word) {
        int n = word.length();

        int res_idx = trie[root].idx;

        for(int i = n - 1; i >= 0; i--) {
            int ch_idx = word[i] - 'a';

            if(trie[root].child[ch_idx] == -1)
                return res_idx;

            root = trie[root].child[ch_idx];
            res_idx = trie[root].idx;
        }

        return res_idx;
    }

public:
    vector<int> stringIndices(vector<string>& wc, vector<string>& wq) {

        int n = wc.size(), m = wq.size();

        trie.reserve(500000); // optional

        int root = getNode(0);

        for(int i = 0; i < n; i++) {
            int idx = trie[root].idx;

            if(wc[idx].length() > wc[i].length() || (wc[idx].length() == wc[i].length() && idx > i))
                trie[root].idx = i;

            insertTrie(root, i, wc);
        }

        vector<int> res(m);

        for(int i = 0; i < m; i++) {
            res[i] = searchTrie(root, wq[i]);
        }

        return res;
    }
};