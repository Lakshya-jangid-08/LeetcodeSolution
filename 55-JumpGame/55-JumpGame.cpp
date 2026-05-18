// Last updated: 5/18/2026, 11:28:21 PM
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int end = nums.size() - 1;
        for (int i = nums.size()-1; i >= 0; i--){
            int jump = i + nums[i];
            if (jump >= end){
                end = i;
            }
        }
        return !end ? true : false;
    }
};