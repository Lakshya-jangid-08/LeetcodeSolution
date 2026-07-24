// Last updated: 7/24/2026, 10:20:16 AM
1class Solution {
2public:
3    string removeDuplicateLetters(string s) {
4
5        vector<int> freq(26, 0), vis(26, 0);
6
7        for(auto &c : s) {
8            int idx = c - 'a';
9            freq[idx]++;
10        }
11
12        string res;
13        for(auto &c : s) {
14            int idx = c - 'a';
15            freq[idx]--;
16            if(vis[idx]) continue;
17            while(!res.empty() && res.back() > c) {
18                int idx2 = res.back() - 'a';
19                if(freq[idx2] > 0) {
20                    vis[idx2] = 0;
21                    res.pop_back();
22                } else break;
23            }
24            res.push_back(c);
25            vis[idx] = 1;
26        }
27
28        return res;
29    }
30};