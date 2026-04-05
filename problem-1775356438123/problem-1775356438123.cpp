// Last updated: 5/4/2026, 8:03:58 am
1class Solution {
2public:
3    int mirrorFrequency(string s) {
4        int alpha[26] = {0};
5        int nums[10] = {0};
6
7        for(char &c : s) {
8            if(isalpha(c)) {
9                alpha[c - 'a']++;
10            } else {
11                nums[c - '0']++;
12            }
13        }
14
15        int ans = 0;
16
17        for(int i = 0; i < 26; i++) {
18            int j = 25 - i;
19            if(i < j) {
20                ans += abs(alpha[i] - alpha[j]);
21            }
22        }
23
24        for(int i = 0; i < 10; i++) {
25            int j = 9 - i;
26            if(i < j) {
27                ans += abs(nums[i] - nums[j]);
28            }
29        }
30
31        return ans;
32    }
33};