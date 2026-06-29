// Last updated: 6/29/2026, 10:23:20 AM
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n <= 2) return n;

        int res = 1;

        for(int i = 0; i < n; i++) {
            unordered_map<string, int> mp;
            int same = 0, maxi = 0;

            for(int j = i + 1; j < n; j++) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];

                if(dx == 0 && dy == 0) {
                    same++;
                    continue;
                }

                int g = __gcd(abs(dx), abs(dy));
                dx /= g;
                dy /= g;

                // normalize sign
                if(dx < 0) {
                    dx *= -1;
                    dy *= -1;
                }
                else if(dx == 0) {
                    dy = 1; // vertical line
                }

                string slope = to_string(dy) + "/" + to_string(dx);
                mp[slope]++;
                maxi = max(maxi, mp[slope]);
            }

            res = max(res, maxi + same + 1);
        }

        return res;
    }
};