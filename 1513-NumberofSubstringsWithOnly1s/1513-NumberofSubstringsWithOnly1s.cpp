// Last updated: 8/21/2026, 1:57:17 PM
1class Solution {
2public:
3    int numSub(string s) {
4        long long result = 0;
5        long long count = 0;
6        int MOD = 1e9 + 7;
7        for(int i = 0; i < s.length(); i++) {
8            if(s[i] == '1') count++;
9            else {
10                result += (count * (count + 1)) / 2;
11                result %= MOD;
12                count = 0;
13            }
14        }
15        result += (count * (count + 1)) / 2;
16        result %= MOD;
17        return result;  
18    }
19};