// Last updated: 6/29/2026, 10:23:25 AM
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> q;
        q.push(beginWord);
        unordered_map<string, bool> mp;

        for(auto &word: wordList) {
            mp[word] = true;
        }
        int op = 0;
        while(!q.empty()) {
            int len = q.size();
            while(len--) {
                string word  = q.front(); q.pop();
                for(int i = 0; i < word.length(); i++) {
                    string next = word;
                    if(next == endWord) return op + 1;
                    for(int x = 0; x < 26; x++) {
                        next[i] = x + 'a';
                        if(mp.count(next) && word != next) {
                            mp.erase(next);
                            q.push(next);
                        }
                    }
                }
            }
            op += 1;
        }
        return 0;
    }
};