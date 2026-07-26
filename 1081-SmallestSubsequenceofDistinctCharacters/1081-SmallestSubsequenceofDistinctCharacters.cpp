// Last updated: 7/26/2026, 10:50:15 AM
1class Solution {
2public:
3    string smallestSubsequence(string s) {
4        vector<int> freq(26, 0);
5
6        for(char &c : s) {
7            freq[c - 'a'] += 1;
8        }
9
10        vector<int> vis(26);
11
12        string st;
13        for(char c : s) {
14            // did not select yet
15            if(!vis[c - 'a']) {
16                while(!st.empty() && st.back() > c) {
17                    if(freq[st.back() - 'a'] > 0) {
18                        vis[st.back() - 'a'] = 0;
19                        st.pop_back();
20                    } else {
21                        break;
22                    }
23                }
24                vis[c - 'a'] = 1;
25                st.push_back(c);
26            }
27            freq[c - 'a']--;
28        }
29        return st;
30    }
31};