// Last updated: 6/29/2026, 10:19:59 AM
class Solution {
    vector<int> pathIdx; 
    long long dp[17][2][8][11];

    long long solve(string s, int idx, int tight, int pos, int prev) {
        if(idx == 16) return (pos == 7);

        if(dp[idx][tight][pos][prev] != -1) return dp[idx][tight][pos][prev];

        int lb = 0;
        int ub = (tight ? s[idx] - '0' : 9);
        long long cnt = 0;
        for(int i = lb; i <= ub; i++) {

            if(pos < 7 && pathIdx[pos] == idx) {
                if(prev == 10 || i >= prev) {
                    cnt += solve(s, idx + 1, (tight && i == ub), pos + 1, i);
                }
            } else {
                cnt += solve(s, idx + 1, (tight && i == ub), pos, prev);
            }
            
        }
        return dp[idx][tight][pos][prev] = cnt;
    }

    string padding(string &s) {
        while(s.size() < 16) s = "0" + s;
        return s;
    }
public:
    long long countGoodIntegersOnPath(long long l, long long r, string directions) {

        vector<vector<int>> matrix(4, vector<int>(4, 0));
        int x = 0, y = 0;

        pathIdx.push_back(0);
        for(auto c : directions) {
            if(c == 'D') {
                x += 1;
            } else {
                y += 1;
            }
            pathIdx.push_back(x * 4 + y);
        } 

        memset(dp, -1, sizeof(dp));
        string left = to_string(l - 1);
        left = padding(left);
        // dp =? idx,  tight, pos, prev
        long long val1 = solve(left, 0, 1, 0, 10);

        
        memset(dp, -1, sizeof(dp));
        string right = to_string(r);
        right = padding(right);
        long long val2 = solve(right, 0, 1, 0, 10);
        // cout << val1 << " " << val2;
        return val2 - val1;
    }
};