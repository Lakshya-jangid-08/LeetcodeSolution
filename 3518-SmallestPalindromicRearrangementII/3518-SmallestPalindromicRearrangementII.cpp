// Last updated: 8/1/2026, 5:03:17 PM
1class Solution {
2public:
3    string smallestPalindrome(string s, int k) {
4        int n = s.length();
5        int bucket[26] = {0};
6        
7        for(int i = 0; i < n / 2; i++) {
8            bucket[s[i] - 'a']++;
9        }
10        
11        auto numOfWays = [&](int rem) -> long long {
12            long long ways = 1;
13            int left = rem;
14
15            auto C = [&](int n, int r) -> long long {
16                if (r > n) return 0;
17                r = min(r, n - r);
18
19                long long ans = 1;
20                for (int i = 1; i <= r; i++) {
21                    ans = ans * (n - r + i) / i;
22                    if (ans >= (long long)k) return (long long)k; // clamp
23                }
24                return ans;
25            };
26
27            for (int c = 0; c < 26; c++) {
28                if (bucket[c] == 0) continue;
29                ways *= C(left, bucket[c]);
30                if (ways >= (long long)k) return (long long)k; // clamp
31                left -= bucket[c];
32            }
33
34            return ways;
35        };
36
37        string left = "";
38        long long startIdx = 0;
39        for(int i = 0; i < n / 2; i++) {
40            for(int c = 0; c < 26; c++) {
41                if(!bucket[c]) continue;
42                bucket[c]--;
43                long long ways = numOfWays(n / 2 - i - 1);
44                if(ways + startIdx >= 1LL * k) {
45                    left.push_back(c + 'a');
46                    break;
47                } 
48                bucket[c]++;
49                startIdx += ways;
50            }
51        }
52
53        if(left.length() < n / 2) return "";
54
55        string mid = (n % 2) ? string(1, s[n/2]) : "";
56        string right = left;
57        reverse(right.begin(), right.end());
58        return left + mid + right;
59    }
60};