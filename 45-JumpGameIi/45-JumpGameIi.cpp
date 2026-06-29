// Last updated: 6/29/2026, 10:23:44 AM
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return 0;
        int maxReach = 0, curr_jump = 0, ans = 0;
        for(int i = 0; i < n; i++) {
            maxReach = max(maxReach, i + nums[i]);

            if(curr_jump == i) {
                ans += 1;
                curr_jump = maxReach;
            }

            if(curr_jump >= n - 1) break;

        }
        return ans;
    }
};