// Last updated: 7/31/2026, 1:20:24 PM
1class Trie {
2private:
3    struct Node {
4        Node* child[26];
5        bool isEnd;
6        vector<string> idxs;
7
8        Node() {
9            isEnd = false;
10            for (int i = 0; i < 26; i++)
11                child[i] = nullptr;
12        }
13    };
14
15    Node* root;
16
17public:
18    Trie() {
19        root = new Node();
20    }
21
22    void insert(string word) {
23        Node* curr = root;
24
25        for (char ch : word) {
26            int idx = ch - 'a';
27            if (curr->child[idx] == nullptr)
28                curr->child[idx] = new Node();
29
30            curr = curr->child[idx];
31            if(curr->idxs.size() >= 3) continue;
32            curr->idxs.push_back(word);
33        }
34
35        curr->isEnd = true;
36    }
37
38    bool search(string word, vector<vector<string>> &res, int k) {
39        Node* curr = root;
40
41        for (char ch : word) {
42            int idx = ch - 'a';
43
44            if (curr->child[idx] == nullptr)
45                return false;
46
47            curr = curr->child[idx];
48            res[k++] = curr->idxs;
49        }
50
51        return curr->isEnd;
52    }
53};
54class Solution {
55public:
56    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
57        // total words ? 
58
59        Trie ts;
60        sort(products.begin(), products.end());
61
62        for(const auto &p : products) {
63            ts.insert(p);
64        }
65
66        vector<vector<string>> res(searchWord.size());
67        ts.search(searchWord, res, 0);
68        return res;
69    }
70};