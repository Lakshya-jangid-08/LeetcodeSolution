// Last updated: 5/29/2026, 12:24:16 PM
1struct Node {
2    Node* child[26];
3    bool flg = false;
4
5    Node() {
6        for(int i = 0; i < 26; i++) {
7            child[i] = nullptr;
8        }
9    }
10
11    bool isContainsKey(char ch) {
12        return (child[ch - 'a'] != nullptr);
13    }
14
15    Node* get(char ch) {
16        return child[ch - 'a'];
17    }
18
19    void setEnd() {
20        flg = true;
21    }
22
23    void put(char ch, Node* node) {
24        child[ch - 'a'] = node;
25    }
26};
27
28class Trie {
29    Node* root;
30public:
31    Trie() {
32        root = new Node();
33    }
34    
35    void insert(string word) {
36        Node* node = root;
37        for(int i = 0; i < word.length(); i++) {
38            if(!node->isContainsKey(word[i])) {
39                node->put(word[i], new Node());
40            }
41            node = node->get(word[i]);
42        }
43        node->setEnd();
44    }
45    
46    bool search(string word) {
47        Node* node = root;
48        for(int i = 0; i < word.length(); i++) {
49            if(!node->isContainsKey(word[i])) return false;
50            node = node->get(word[i]);
51        }
52        return (node->flg == true);
53    }
54    
55    bool startsWith(string prefix) {
56        Node* node = root;
57        for(int i = 0; i < prefix.length(); i++) {
58            if(!node->isContainsKey(prefix[i])) return false;
59            node = node->get(prefix[i]);
60        }    
61        return true;
62    }
63
64};
65
66/**
67 * Your Trie object will be instantiated and called as such:
68 * Trie* obj = new Trie();
69 * obj->insert(word);
70 * bool param_2 = obj->search(word);
71 * bool param_3 = obj->startsWith(prefix);
72 */