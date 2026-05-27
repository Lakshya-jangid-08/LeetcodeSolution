// Last updated: 5/27/2026, 12:07:58 PM
1class Solution {
2public:
3    int numberOfSpecialChars(string word) {
4        vector<int> lowerIdx(26, -1);
5
6        int idx = 0;
7        for(auto &c : word) {
8            if(c <= 'z' && c >= 'a') lowerIdx[c - 'a'] = idx;
9            idx++;
10        }
11
12        idx = 0;
13        int cnt = 0;
14        for(auto &c : word) {
15            if(c >= 'A' && c <= 'Z' && lowerIdx[c - 'A'] != -1) {
16                cout << idx << endl;
17                if(lowerIdx[c - 'A'] < idx) cnt++;
18                lowerIdx[c - 'A'] = -1;
19            }
20            idx++;
21        }
22
23        return cnt;
24    }
25};