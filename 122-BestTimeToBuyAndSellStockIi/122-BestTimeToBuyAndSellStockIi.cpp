// Last updated: 6/29/2026, 10:23:30 AM

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = 1e5;
        int res = 0;
        for(auto & p : prices) {
            res += max(0, p - minPrice);
            minPrice = p;
        }   
        return res;
    }
};