// Last updated: 7/29/2026, 11:23:04 PM
1class Solution {
2private:
3    long long comb(long long n, long long m, long long k) {
4        long long res = 1;
5        m = std::min(m, n - m);
6
7        for (long long i = 1; i <= m; i++) {
8            res = res * (n - i + 1) / i;
9            if (res > k) {
10                return k + 1;
11            }
12        }
13        return res;
14    }
15
16public:
17    std::string smallestPalindrome(std::string s, long long k) {
18        int partition = s.length() / 2;
19        std::vector<int> bucket(26, 0);
20
21        for (int i = 0; i < partition; i++) {
22            bucket[s[i] - 'a'] += 1;
23        }
24
25        auto permutations = [&](int rem) {
26            long long ways = 1;
27            for (int i = 0; i < 26; i++) {
28                if (bucket[i] == 0) {
29                    continue;
30                }
31
32                ways *= comb(rem, bucket[i], k);
33                if (ways > k) {
34                    break;
35                }
36                rem -= bucket[i];
37            }
38            return ways;
39        };
40
41        std::string left = "";
42        long long startIndex = 1;
43
44        for (int pos = 0; pos < partition; pos++) {
45            for (int i = 0; i < 26; i++) {
46                if (bucket[i] == 0) {
47                    continue;
48                }
49
50                bucket[i] -= 1;
51
52                long long ways = permutations(partition - pos - 1);
53                if (startIndex + ways > k) {
54                    left += (char)(i + 'a');
55                    break;
56                }
57
58                bucket[i] += 1;
59                startIndex += ways;
60            }
61        }
62
63        if (left.length() < partition) {
64            return "";
65        }
66
67        std::string mid =
68            s.length() % 2 != 0 ? std::string(1, s[partition]) : "";
69        std::string right = left;
70        std::reverse(right.begin(), right.end());
71
72        return left + mid + right;
73    }
74};