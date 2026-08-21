// Last updated: 8/21/2026, 5:13:32 PM
1class Solution {
2public:
3    int numDistinct(string s, string t) {
4        int n = s.length(), m = t.length();
5        vector<unsigned long long>prev(m + 1, 0), curr(m + 1, 0);
6        
7        prev[m] = 1;
8        for(int i = n - 1; i >= 0; i--) {
9            fill(curr.begin(), curr.end(), 0);
10            curr[m] = 1; 
11            for(int j = m - 1; j >= 0; j--) {
12                if(s[i] == t[j]) {
13                    curr[j] += prev[j + 1]; 
14                }
15                curr[j] += prev[j];
16            }
17            swap(prev, curr);
18        }
19
20        return prev[0];
21    }
22};