// Last updated: 6/29/2026, 10:23:58 AM
struct Node {
    Node* child[26];
    bool flg = false;

    Node() {
        for(int i = 0; i < 26; i++) {
            child[i] = nullptr;
        }
    }

    bool isContainsKey(char ch) {
        return (child[ch - 'a'] != nullptr);
    }

    Node* get(char ch) {
        return child[ch - 'a'];
    }

    void setEnd() {
        flg = true;
    }

    void put(char ch, Node* node) {
        child[ch - 'a'] = node;
    }
};

class Trie {
    Node* root;
 public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        for(int i = 0; i < word.length(); i++) {
            if(!node->isContainsKey(word[i])) {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        Node* node = root;
        for(int i = 0; i < word.length(); i++) {
            if(!node->isContainsKey(word[i])) return false;
            node = node->get(word[i]);
        }
        return (node->flg == true);
    }

    string longestPrefix() {
        Node* node = root;
        string curr = "";

        while(1) {
            int cnt = 0;
            char c = '0';
            for(int i = 0; i < 26; i++) {
                if(node->isContainsKey('a' + i)) {
                    c = 'a' + i;
                    cnt++;
                }
            }
            if(cnt == 1) {
                curr.push_back(c);
                node = node->get(c);
            } 

            if(node->flg || cnt != 1) return curr;

        }
        return curr;
    }

};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie* tree = new Trie();

        for(auto &s : strs) {
            if(s == "") return "";
            tree->insert(s);
        }

        return tree->longestPrefix();

    }
};