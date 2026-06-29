// Last updated: 6/29/2026, 10:23:06 AM
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
    
    bool startsWith(string prefix) {
        Node* node = root;
        for(int i = 0; i < prefix.length(); i++) {
            if(!node->isContainsKey(prefix[i])) return false;
            node = node->get(prefix[i]);
        }    
        return true;
    }

};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */