// Last updated: 6/29/2026, 10:20:11 AM
class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int Xor = 0;
        bool onlyZero = true;

        for(int i = 0; i < nums.size(); i++) {
            Xor ^= nums[i];
            if(nums[i]) onlyZero = false;
        }

        return Xor ? nums.size() : onlyZero ? 0 : nums.size() - 1;
    }
};