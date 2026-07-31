// Last updated: 7/31/2026, 10:50:13 AM
1class Solution {
2public:
3    int minimumPushes(string &word) {
4        vector<int> freq(26, 0);
5        for (char c : word) {
6            freq[c - 'a']++;
7        }
8        sort(freq.rbegin(),freq.rend());
9
10        int cost = 0;
11        for(int i = 0 ;i < 26; i++) {
12            int push = (i/8)+1;
13            cost += freq[i]*push;
14        }
15        return cost;
16    }
17};