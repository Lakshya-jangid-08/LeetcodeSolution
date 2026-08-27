// Last updated: 8/28/2026, 2:04:36 AM
1class Solution {
2public:
3    string lexGreaterPermutation(string s, string target) {
4        vector<int> cnt(26, 0);
5        for (char c : s) {
6            cnt[c - 'a']++;
7        }
8
9        string res;
10        int n = target.size();
11        for (int i = 0; i < n; i++) {
12            int targetChar = target[i] - 'a';
13
14            // Case 1: First try to place the same character as target[i] at the
15            // current position
16            if (cnt[targetChar] > 0) {
17                cnt[targetChar]--;
18                // Check if the remaining characters can form a string greater
19                // than target[i+1:]
20                if (canFormGreater(cnt, target, i + 1)) {
21                    res.push_back(target[i]);
22                    continue;
23                }
24                // Cannot form a larger string, backtrack
25                cnt[targetChar]++;
26            }
27
28            // Case 2: Place a character greater than target[i] at the current
29            // position
30            for (int j = targetChar + 1; j < 26; j++) {
31                if (cnt[j] > 0) {
32                    cnt[j]--;
33                    res.push_back('a' + j);
34                    // Fill remaining positions with the smallest
35                    // lexicographical order
36                    res += getMinString(cnt);
37                    return res;
38                }
39            }
40
41            // No feasible solution found, return directly
42            return "";
43        }
44
45        return "";
46    }
47
48private:
49    // Check if the remaining characters can form a string greater than the
50    // suffix.
51    bool canFormGreater(const vector<int>& cnt, const string& target,
52                        int start) {
53        string maxStr = getMaxString(cnt);
54        string suffix = target.substr(start);
55        return maxStr > suffix;
56    }
57
58    // Get the maximum lexicographical string (in descending order)
59    string getMaxString(const vector<int>& cnt) {
60        string res;
61        for (int i = 25; i >= 0; i--) {
62            res.append(cnt[i], 'a' + i);
63        }
64        return res;
65    }
66
67    // Get the lexicographically smallest string (in ascending order)
68    string getMinString(const vector<int>& cnt) {
69        string res;
70        for (int i = 0; i < 26; i++) {
71            res.append(cnt[i], 'a' + i);
72        }
73        return res;
74    }
75};