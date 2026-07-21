// Last updated: 7/21/2026, 12:54:37 PM
1class Solution {
2public:
3    int maxActiveSectionsAfterTrade(string s) {
4        int n = s.length();
5        vector<int> cntZero;
6        int i = 0, j = n - 1;
7        while(i < n && s[i] != '0') i++;
8        while(j > i && s[j] != '0') j--;
9        int count = 0;
10        for(i ; i <= j; i++) {
11            if(s[i] == '1') {
12                if(count == 0) continue;
13                cntZero.push_back(count);
14                count = 0;
15            } else {
16                count += 1;
17            }
18        }
19        if(count)
20            cntZero.push_back(count);
21
22        int gain = 0;
23        for(int i = 0; i + 1 < cntZero.size(); i++) {
24            gain = max(gain, cntZero[i] + cntZero[i + 1]);
25        }
26        
27        for(int i = 0; i < n; i++) {
28            if(s[i] == '0') continue;
29            gain += 1;
30        }
31
32        return gain;
33    }
34};