// Last updated: 7/27/2026, 10:34:37 PM
1class Solution {
2public:
3    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
4        unordered_set<string> dic(words.begin(), words.end());
5        vector<string> res;
6
7        for(auto &word : words) {
8            int m = word.size();
9            vector<bool> dp(m + 1, false);
10            dp[0] = true;
11            for(int i = 1; i <= m; i++) {
12                for(int j = (i == m ? 1 : 0); !dp[i] && j < i; j++) {
13                    dp[i] = dp[j] && dic.count(word.substr(j, i - j));
14                }
15            }
16            if(dp[m]) res.push_back(word);
17        }
18
19        return res;
20    }
21};