// Last updated: 6/29/2026, 10:20:20 AM
class Solution {
public:

    int solve(vector<int>& a1, vector<int>& a2, vector<int>& b1, vector<int> &b2) {
        
        int finish = 1e9;

        for(int i = 0; i < a1.size(); i++) {
            finish = min(finish, a1[i] + a2[i]);
        }

        int res = 1e9;
        for(int i = 0; i < b1.size(); i++) {
            res = min(
                res ,
                max(finish, b1[i]) + b2[i]
            );
        }
        return res;
    }

    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        // I have two options 
        // land-water
        // water-land
        int res1 = solve(landStartTime, landDuration, waterStartTime, waterDuration);
        int res2 = solve(waterStartTime, waterDuration, landStartTime, landDuration);
        return min(res1, res2);
    }
};