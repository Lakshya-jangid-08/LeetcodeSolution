// Last updated: 7/27/2026, 7:38:25 PM
1class Solution {
2    bool solve(string &s, int idx, unordered_set<string> &st, vector<int> &dp, int cnt) {
3        if (idx == s.size())
4            return cnt >= 2;
5
6        if (dp[idx] != -1)
7            return dp[idx];
8
9        string cur;
10
11        for (int i = idx; i < s.size(); i++) {
12            cur.push_back(s[i]);
13
14            if (st.count(cur)) {
15                if (solve(s, i + 1, st, dp, cnt + 1))
16                    return dp[idx] = true;
17            }
18        }
19
20        return dp[idx] = false;
21    }
22
23public:
24    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
25
26        unordered_set<string> st(words.begin(), words.end());
27
28        vector<string> ans;
29
30        for (string &word : words) {
31
32            st.erase(word);               // don't allow using itself
33
34            vector<int> dp(word.size(), -1);
35
36            if (solve(word, 0, st, dp, 0))
37                ans.push_back(word);
38
39            st.insert(word);
40        }
41
42        return ans;
43    }
44};