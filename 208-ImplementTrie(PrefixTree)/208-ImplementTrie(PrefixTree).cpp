// Last updated: 6/2/2026, 2:46:17 PM
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
30 public:
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
55    string longestPrefix() {
56        Node* node = root;
57        string curr = "";
58
59        while(1) {
60            int cnt = 0;
61            char c = '0';
62            for(int i = 0; i < 26; i++) {
63                if(node->isContainsKey('a' + i)) {
64                    c = 'a' + i;
65                    cnt++;
66                }
67            }
68            if(cnt == 1) {
69                curr.push_back(c);
70                node = node->get(c);
71            } 
72
73            if(node->flg || cnt != 1) return curr;
74
75        }
76        return curr;
77    }
78
79};
80
81class Solution {
82public:
83    string longestCommonPrefix(vector<string>& strs) {
84        Trie* tree = new Trie();
85
86        for(auto &s : strs) {
87            if(s == "") return "";
88            tree->insert(s);
89        }
90
91        return tree->longestPrefix();
92
93    }
94};