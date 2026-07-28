// Last updated: 7/28/2026, 10:49:40 AM
1class Solution {
2public:
3    string smallestPalindrome(string s) {
4        int len = s.length();
5        int partition = len / 2;
6
7        sort(s.begin(), s.begin() + partition);
8        cout << s ;
9        for (int i = 0; i < partition; ++i) {
10            s[len - 1 - i] = s[i];
11        }
12
13        return s;
14    }
15};