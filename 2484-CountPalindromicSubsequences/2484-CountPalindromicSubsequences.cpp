// Last updated: 9/6/2026, 5:21:30 PM
1class Solution {
2    using ll = long long;
3    const ll mod = 1e9 + 7;
4    vector<vector<vector<int>>> calc(string &s) {
5        int freq[10] = {0};
6        int n = s.length();
7        vector<vector<vector<int>>> res(n, vector<vector<int>>(10, vector<int>(10, 0)));
8        
9        for(int idx = 0; idx < n; idx++) {
10            int num = s[idx] - '0';
11            
12            if(idx > 0) {
13                for(int i = 0; i < 10; i++) {
14                    for(int j = 0; j < 10; j++) {
15                        res[idx][i][j] = res[idx - 1][i][j];
16                    }
17                }
18            }
19
20            for(int i = 0; i < 10; i++) {
21                res[idx][i][num] += freq[i];
22            }
23
24            freq[num] += 1;
25        }
26        return res;
27    };
28
29public:
30    int countPalindromes(string s) {
31        auto prefixArr = calc(s);
32        reverse(s.begin(), s.end());
33        auto suffixArr = calc(s);
34        reverse(suffixArr.begin(), suffixArr.end());
35
36        int n = s.length();
37        ll count = 0;
38        for(int i = 2; i < n - 2; i++) {
39            for(int p = 0; p < 10; p++) {
40                for(int q = 0; q < 10; q++) {
41                    count += 1LL * prefixArr[i - 1][p][q] * suffixArr[i + 1][p][q];
42                    count %= mod;
43                }
44            }
45        }
46        return count;
47    }
48};