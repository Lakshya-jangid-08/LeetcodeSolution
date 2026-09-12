// Last updated: 9/12/2026, 8:22:15 PM
1class Solution {
2public:
3    int totalNumbers(vector<int>& digits) {
4        int n = digits.size();
5        bool vis[1000]{};
6        int ans = 0;
7
8        for (int i = 0; i < n; ++i) {
9            if (digits[i] == 0) {
10                continue;
11            }
12            for (int j = 0; j < n; ++j) {
13                if (j == i) {
14                    continue;
15                }
16                for (int k = 0; k < n; ++k) {
17                    if (k == i || k == j || digits[k] % 2 != 0) {
18                        continue;
19                    }
20                    int x = digits[i] * 100 + digits[j] * 10 + digits[k];
21                    if (!vis[x]) {
22                        vis[x] = true;
23                        ++ans;
24                    }
25                }
26            }
27        }
28
29        return ans;
30    }
31};