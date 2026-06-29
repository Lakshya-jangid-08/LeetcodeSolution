// Last updated: 6/29/2026, 10:19:38 AM
class Solution {
public:
    long long minOperations(vector<int>& nums) {
        long long x = 0;
        for(int i = 1; i < nums.size(); i++){
            int diff = nums[i - 1] - nums[i];
            if(diff > 0) {
                x += diff;
            }
        }
        return x;
    }
};