// Last updated: 6/29/2026, 10:23:31 AM
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = 1e5;
        int res = 0;
        for(auto & p : prices) {
            minPrice = min(p, minPrice);
            res = max(res, p - minPrice);
        }   
        return res;
    }
};