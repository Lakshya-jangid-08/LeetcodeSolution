// Last updated: 6/29/2026, 10:19:36 AM
class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        vector<int> res;

        for(auto row : matrix) {
            int cnt = 0;
            for(auto val : row) {
                if(val == 0) continue;
                cnt++;
            }
            res.push_back(cnt);
        }
        return res;
    }
};