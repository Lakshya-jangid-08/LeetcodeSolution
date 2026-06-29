// Last updated: 6/29/2026, 10:20:41 AM
class Solution {

    struct trieNode {
        trieNode* child[10];

        trieNode() {
            for(int i = 0; i < 10; i++) child[i] = nullptr;
        }
    };

    trieNode* root;

    void insertTrie(string word) {
        trieNode* node = root;
        for(int i = 0; i < word.length(); i++) {
            int chIdx = word[i] - '0';
            if(node->child[chIdx] == nullptr) {
                node->child[chIdx] = new trieNode();
            }       
            node = node->child[chIdx];
        }
    }

    int searchTrie(string word) {
        trieNode* node = root;
        int len = 0;
        for(int i = 0; i < word.length(); i++) {
            int chIdx = word[i] - '0';
            if(node->child[chIdx] == nullptr) return len;     
            node = node->child[chIdx];
            len += 1;
        }
        return len;
    }

 public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        root = new trieNode();
        for(auto &arr : arr1) {
            string s = to_string(arr);
            insertTrie(s);
        }
        int res = 0;
        for(auto &arr : arr2) {
            string s = to_string(arr);
            res = max(res, searchTrie(s));
        }
        return res;
    }
};