// Last updated: 8/23/2026, 11:28:25 PM
1class Solution {
2public:
3    bool sumGame(string num) {
4        int n = num.size();
5
6        auto get = [](string&& s) -> pair<int, int> {
7            int nn = 0, qq = 0;
8            for (char ch : s) {
9                if (ch == '?') {
10                    ++qq;
11                } else {
12                    nn += (ch - '0');
13                }
14            }
15            return {nn, qq};
16        };
17
18        auto [n0, q0] = get(num.substr(0, n / 2));
19        auto [n1, q1] = get(num.substr(n / 2, n / 2));
20
21        return ((q0 + q1) % 2 == 1) || (n0 - n1 != (q1 - q0) * 9 / 2);
22    }
23};