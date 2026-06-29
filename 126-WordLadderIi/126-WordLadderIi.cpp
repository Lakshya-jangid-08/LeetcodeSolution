// Last updated: 6/29/2026, 10:23:27 AM
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> q;
        q.push(beginWord);
        unordered_map<string, bool> mp;

        for(auto &word: wordList) {
            mp[word] = true;
        }
        int op = 0;

        unordered_map<string, int> stepmp;

        if(!mp.count(endWord))
            return {};
            
        const auto bfs = [&]() -> int {
            int op = 0;
            while(!q.empty()) {
                int len = q.size();
                while(len--) {
                    string word  = q.front(); q.pop();
                    stepmp[word] = op;
                    for(int i = 0; i < word.length(); i++) { // O(L)
                        string next = word; // O(L)
                        for(int x = 0; x < 26; x++) { // O(26)
                            next[i] = x + 'a';
                            if(next == endWord) {
                                stepmp[next] = op + 1;
                                return op + 1;
                            }
                            if(mp.count(next) && word != next){
                                if(!stepmp.count(next)){
                                    stepmp[next] = op + 1;
                                    q.push(next);
                                }
                            }
                        }
                    }
                }
                op += 1;
            }
            return 0;
        };

        op = bfs();
        if(op == 0) return {};
        vector<vector<string>> res;
        const auto solve = [&](auto &&self, int currStep, string currWord, vector<string> &temp) ->void {

            temp.push_back(currWord);
            if(currStep < 0) {
                temp.pop_back();
                return;
            }
            if(currWord == beginWord) {
                res.push_back(temp);
                temp.pop_back();
                return;
            }

            for(int i = 0; i < currWord.size(); i++){
                string t = currWord;
                for(int x = 0; x < 26; x++) {
                    t[i] = x + 'a';
                    if(t != currWord && stepmp.count(t) && stepmp[t] == currStep - 1) {
                        self(self, currStep -1, t, temp);
                    }
                }
            }
            temp.pop_back();
        }; 

        string currWord = endWord;
        int currStep = stepmp[currWord];
        vector<string> temp;
        
        solve(solve, currStep, currWord, temp); 

        for(auto &r : res) {
            reverse(r.begin(), r.end());
        }

        return res;
    }
};