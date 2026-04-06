// Last updated: 6/4/2026, 10:19:16 pm
class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int totalXor = 0, nonZero = 0, n = nums.size();

        for (int& num : nums) {
            totalXor ^= num;

            if (num != 0)
                nonZero = 1;
        }

        return totalXor ? n : nonZero ? n - 1 : 0;
    }
};