// Last updated: 6/29/2026, 10:21:32 AM
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int sum = 0, res = 0;
        for(auto &g : gain) {
            sum += g;
            res = max(res, sum);
        }
        return res;
    }
};