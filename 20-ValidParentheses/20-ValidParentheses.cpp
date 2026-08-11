// Last updated: 8/11/2026, 8:49:40 PM
1class Solution {
2public:
3    bool isValid(string s) {
4        stack<char> st;
5        for (char ch : s) {
6            if (ch == '(' || ch == '[' || ch == '{') {
7                st.push(ch);
8            } else {
9                if (st.empty()) {
10                    return false;
11                }
12                char top = st.top();
13                st.pop();
14                if (ch == ')' && top != '(') return false;
15                if (ch == ']' && top != '[') return false;
16                if (ch == '}' && top != '{') return false;
17            }
18        }
19        return st.empty();
20    }
21};