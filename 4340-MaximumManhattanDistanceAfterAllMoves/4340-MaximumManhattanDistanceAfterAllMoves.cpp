// Last updated: 6/29/2026, 10:19:13 AM
class Solution {
public:
    int maxDistance(string moves) {
        int x = 0, y = 0;

        const auto use = [](int &x, int &y, char c) {
            if(c == 'U') y++;
            else if(c == 'D') y--;
            else if(c == 'L') x--;
            else if(c == 'R') x++;
            else {
                if(x > 0) x++;
                else x--;
            }
        };
        int cnt = 0;
        for(auto &c : moves) {
            if(c == '_') {
                cnt++;
                continue;
            }
            use(x, y, c);
        }
        return cnt + abs(x) + abs(y);
    }
};