// Last updated: 12/4/2026, 9:15:37 am
1class Solution {
2public:
3    int longestBalanced(string s) {
4        unordered_map<int, pair<int, int>> mp;
5
6        int ones = 0, zeros = 0;
7        for(auto c : s) {
8            if(c=='0') zeros++;
9            else ones++;
10        }
11        if(ones == zeros) return s.length();
12        if(ones == 0 || zeros == 0) return 0;
13
14        mp[0] = {-1, -2};
15        int curr = 0, maxlen = 0;
16        for(int i = 0; i < s.length(); i++) {
17            curr += (s[i] == '0' ? - 1 : 1);
18
19            if(mp.count(curr)) {
20                maxlen = max(maxlen, i - mp[curr].first);
21            }
22
23            int t1 = curr - 2; // means 2 extra 1's need to replace with one 0's
24            if(mp.count(t1)) {
25                int width  = i - mp[t1].first;
26                int currZero = (width - 2) / 2;
27                if(currZero < zeros) {
28                    maxlen = max(maxlen, width);
29                }
30                else if(mp[t1].second != -2) {
31                    maxlen = max(maxlen, i - mp[t1].second);
32                }
33            }
34            int t2 = curr + 2; // opppo;
35            if(mp.count(t2)) {
36                int width  = i - mp[t2].first;
37                int currOne = (width - 2) / 2;
38                if(currOne < ones) {
39                    maxlen = max(maxlen, width);
40                }
41                else if(mp[t2].second != -2) {
42                    maxlen = max(maxlen, i - mp[t2].second);
43                }
44            }
45
46
47            if(mp.count(curr) == 0) {
48                mp[curr] = {i, -2};
49            } else if(mp[curr].second == -2) {
50                mp[curr].second = i;
51            }
52            
53        }
54        return maxlen;
55        
56    }
57};