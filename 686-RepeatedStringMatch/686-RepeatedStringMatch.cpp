// Last updated: 9/4/2026, 2:07:54 AM
1class Solution {
2public:
3    int repeatedStringMatch(string a, string b) {
4        int n = a.length(), m = b.length();
5        if(!m) return 0;
6        int ans = 1e8;
7        for(int i = 0; i < n; i++) {
8            if(a[i] == b[0]) {
9                int count = 0;
10                int k = i, j = 0;
11                while(j < m && a[k] == b[j]) {
12                    k = (k + 1) % n;
13                    j += 1;
14                    count += (k == 0 && j < m) ? 1 : 0; 
15                }
16                if(j == m) {
17                    ans = min(ans, 1 + count);
18                }
19            }
20        }
21        if(ans == 1e8) return -1;
22        return ans;
23
24    }
25};