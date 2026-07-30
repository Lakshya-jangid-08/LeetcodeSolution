// Last updated: 7/30/2026, 3:08:53 PM
1class Solution {
2public:
3    int minimumPushes(string word) {
4        auto [q, r] = div(word.size(), 8);
5        return r * (q + 1) + q * (q + 1) * 4;
6    }
7};