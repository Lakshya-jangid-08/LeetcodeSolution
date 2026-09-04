// Last updated: 9/4/2026, 9:29:42 AM
1class Solution {
2public:
3    const int BASE = 100000;
4    int repeatedStringMatch(string A, string B) {
5        int n = A.length(), m = B.length();
6
7        if(n == 0 || m == 0) return -1;
8
9        string source = A;
10        int repeat = 1;
11        while(source.length() < m) {
12            source += A;
13            repeat += 1;
14        }
15
16        const auto Rabin_Krap_Algo = [&](string & source) -> bool {
17            n = source.length();
18            string & target = B;
19            int power = 1;
20            int targetCode = 0;
21            for(int i = 0; i < m; i++) {
22                targetCode = (target[i] + targetCode * 31) % BASE;
23                power = (power * 31) % BASE;
24            }
25
26            int hashCode = 0;
27            for(int i = 0; i < n; i++) {
28                hashCode = (hashCode * 31 + source[i]) % BASE;
29                if(i < m - 1) 
30                    continue;
31                if(i >= m)
32                    hashCode = (hashCode - source[i - m] * power) % BASE;
33                if(hashCode < 0) 
34                    hashCode += BASE;
35                if(hashCode == targetCode) 
36                    if(source.substr(i - m + 1, m) == target) 
37                        return true;
38            }
39            return false;
40        };
41
42        if(Rabin_Krap_Algo(source)) return repeat;
43        source += A;
44        if(Rabin_Krap_Algo(source)) return repeat + 1;
45        return -1;
46    }
47};