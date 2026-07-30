// Last updated: 7/30/2026, 3:03:06 PM
1class Solution {
2public:
3    int minimumPushes(string word) {
4        vector<int> cmp(26, 0);
5        for (char c : word) {
6            cmp[c - 'a']++;
7        }
8
9        vector<pair<int, char>> cp;
10
11        for (auto [idx, val] : views::enumerate(cmp)) {
12            cp.push_back({val, static_cast<char>('a' + idx)});
13        }
14
15        // 
16        sort(cp.begin(), cp.end(), [](pair<int, char> &a, pair<int, char> &b) {
17            return a.first > b.first;
18        });
19        
20        int cost = 0;
21
22        for (int i = 0; i < cp.size(); i++) {
23            int presses = i / 8 + 1;   // first 8 -> 1, next 8 -> 2, next 8 -> 3, last 2 -> 4
24            cost += presses * cp[i].first;
25        }
26
27        return cost;
28
29    }
30};