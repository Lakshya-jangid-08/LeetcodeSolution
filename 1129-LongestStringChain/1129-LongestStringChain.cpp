// Last updated: 6/29/2026, 10:21:55 AM
class Solution {
public:
    vector<int> dp;

    bool isMatch(string &s, string &t) {
        if (s.length() != t.length() + 1)
            return false;

        int i = 0, j = 0;

        while (i < s.length()) {
            if (j < t.length() && s[i] == t[j]) {
                i++;
                j++;
            } else {
                i++;
            }
        }

        return j == t.length();
    }

    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(),
             [](string &a, string &b) {
                 return a.size() < b.size();
             });

        int n = words.size();
        dp.assign(n, 0);

        int ans = 1;

        for (int i = n-1; i >= 0; i--) {
            int temp = 1;
            for (int j = i + 1; j < words.size(); j++) {
                if (isMatch(words[j], words[i])) {
                    temp = max(temp, 1 + dp[j]);
                }
            }
            dp[i] = temp;
            ans = max(ans, dp[i]);
        }

        return ans;
    }
};