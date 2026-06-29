// Last updated: 6/29/2026, 10:21:30 AM
class Solution {
public:
    bool check(vector<int>& nums) {
        int pivot = 1;

        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] < nums[i-1]) pivot--;
        }
        if(nums[0] < nums[nums.size() - 1]) pivot--;
        return (pivot >= 0);
    }
};