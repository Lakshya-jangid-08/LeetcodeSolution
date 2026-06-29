// Last updated: 6/29/2026, 10:21:14 AM
class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        if(rows == 1) return encodedText;
        int len = encodedText.length();

        int d = len / rows;
        vector<bool> visit(len + 1, false);
        string res = "";
        for(int i = 0; i < len; i++) {
            if(visit[i]) continue;
            int curr = i;
            while(curr < len && !visit[curr]) {
                res += encodedText[curr];
                visit[curr] = true;
                curr += d+1;
            }
        }
        for(int i = res.length() - 1; i >= 0; i--) {
            if(res[i]==' ') res.pop_back();
            else break;
        }
        return res;
    }
};
