// Last updated: 5/26/2026, 8:58:24 PM
1class Solution {
2public:
3    int numberOfSpecialChars(string word) {
4        unordered_map<char, bool> islower;
5
6        for(auto c : word) {
7            if('a' <= c && c <= 'z') {
8                islower[c] = true;
9            }
10        }
11
12        int cnt = 0;
13        for(auto c : word) {
14            if('A' <= c && c <= 'Z' && islower[c+32]) {
15                cnt++;
16                islower[c+32] = false;
17            }
18        }
19
20        return cnt;
21    }
22};