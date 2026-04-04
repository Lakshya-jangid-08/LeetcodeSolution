// Last updated: 4/4/2026, 10:16:47 am
1class Solution {
2public:
3    string decodeCiphertext(string encodedText, int rows) {
4        if(rows == 1) return encodedText;
5        int len = encodedText.length();
6
7        int d = len / rows;
8        vector<bool> visit(len + 1, false);
9        string res = "";
10        for(int i = 0; i < len; i++) {
11            if(visit[i]) continue;
12            int curr = i;
13            while(curr < len && !visit[curr]) {
14                res += encodedText[curr];
15                visit[curr] = true;
16                curr += d+1;
17            }
18        }
19        for(int i = res.length() - 1; i >= 0; i--) {
20            if(res[i]==' ') res.pop_back();
21            else break;
22        }
23        return res;
24    }
25};
26