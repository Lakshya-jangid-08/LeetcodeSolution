// Last updated: 6/29/2026, 10:21:06 AM
class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end());
        int total =0;

        for(int i=cost.size()-1;i>=0;i-=3){
            total += cost[i];
            if(i-1>=0) total+=cost[i-1];
        }

        return total;
    }
};