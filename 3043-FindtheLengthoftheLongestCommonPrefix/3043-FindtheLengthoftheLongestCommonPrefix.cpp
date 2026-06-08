// Last updated: 6/8/2026, 3:01:41 PM
1class Solution {
2
3    struct trieNode {
4        trieNode* child[10];
5
6        trieNode() {
7            for(int i = 0; i < 10; i++) child[i] = nullptr;
8        }
9    };
10
11    trieNode* root;
12
13    void insertTrie(string word) {
14        trieNode* node = root;
15        for(int i = 0; i < word.length(); i++) {
16            int chIdx = word[i] - '0';
17            if(node->child[chIdx] == nullptr) {
18                node->child[chIdx] = new trieNode();
19            }       
20            node = node->child[chIdx];
21        }
22    }
23
24    int searchTrie(string word) {
25        trieNode* node = root;
26        int len = 0;
27        for(int i = 0; i < word.length(); i++) {
28            int chIdx = word[i] - '0';
29            if(node->child[chIdx] == nullptr) return len;     
30            node = node->child[chIdx];
31            len += 1;
32        }
33        return len;
34    }
35
36 public:
37    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
38        root = new trieNode();
39        for(auto &arr : arr1) {
40            string s = to_string(arr);
41            insertTrie(s);
42        }
43        int res = 0;
44        for(auto &arr : arr2) {
45            string s = to_string(arr);
46            res = max(res, searchTrie(s));
47        }
48        return res;
49    }
50};