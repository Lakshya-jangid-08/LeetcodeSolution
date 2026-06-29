// Last updated: 6/29/2026, 10:21:56 AM
struct Node {
    Node * child[26];
    bool flg;

    Node() {
        for(int i = 0; i < 26; i++) {
            child[i] = nullptr;
        }
        flg = false;
    }

    bool isContainsKey(char ch) {
        return (child[ch - 'a'] != nullptr); 
    }

    void put(char ch, Node* node) {
        child[ch - 'a'] = node;
        return;
    }

    Node* get(char ch) {
        return child[ch - 'a'];
    }

    void setEnd() {
        flg = true;
    }
};

class StreamChecker {
    Node* root;
    string s;
    void insert(string& word) {
        Node* node = root;
        
        for(int i = word.length() - 1; i >= 0; i--) {
            if(!node->isContainsKey(word[i])) {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }

        node->setEnd();
        return;
    }

    bool search(string& word) {
        Node* node = root;
        // cout << "for : " << word << " ";
        for(int i = word.length() - 1; i >= 0; i--) {
            if(node->flg) return true; 
            if(!node->isContainsKey(word[i])) return false;
            node = node->get(word[i]);
        }
        return (node->flg);
    }
public:
    StreamChecker(vector<string>& words) {
        s = "";
        root = new Node(); 
        for(auto it : words) {
            insert(it);
        }
    }
    
    bool query(char letter) {
        s.push_back(letter);
        // cout << endl;
        return search(s);
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */