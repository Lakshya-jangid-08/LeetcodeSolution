// Last updated: 6/29/2026, 10:20:33 AM
class Solution {
    
    int digSum(int digit) {
        int res = 0;
        while(digit > 0) {
            res += digit % 10;
            digit /= 10;
        }
        return res;
    }

public:
    int minElement(vector<int>& nums) {
        
        int res = 1e9;

        for(int i = 0; i < nums.size(); i++) {
            res = min(res, digSum(nums[i]));
        }

        return res;
    }
};