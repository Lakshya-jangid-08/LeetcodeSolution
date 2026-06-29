// Last updated: 6/29/2026, 10:21:33 AM
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int maxCost = *max_element(costs.begin(), costs.end());

        vector<int> count(maxCost + 1, 0);
        for(auto &c : costs) {
            count[c]++;
        }

        int res = 0;

        for(int i = 1; i <= maxCost; i++) {
            if(count[i] == 0) continue;

            int canBuy = coins / i;
            if(canBuy <= count[i]) {
                return res + canBuy;
            }
            res += count[i];
            coins -= count[i] * i; 
        }
        return res;
    }
};