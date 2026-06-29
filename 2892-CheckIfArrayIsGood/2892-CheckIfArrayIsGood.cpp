// Last updated: 6/29/2026, 10:20:53 AM
class Solution {
public:
    bool isGood(vector<int>& nums) {

        int m = nums.size();

        if(m < 2)
            return false;

        sort(nums.begin(), nums.end());

        int n = m - 1;

        for(int i = 0; i < n - 1; i++) {
            if(nums[i] != i + 1)
                return false;
        }

        return nums[n - 1] == n && nums[n] == n;
    }
};