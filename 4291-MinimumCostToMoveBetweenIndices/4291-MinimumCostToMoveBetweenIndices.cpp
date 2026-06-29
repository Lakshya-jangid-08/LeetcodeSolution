// Last updated: 6/29/2026, 10:19:20 AM
class Solution {
public:
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> forward(n), backward(n);

        // closet
        forward[0] = backward[n-1] = 0;
        for(int i = 0; i < n-1; i++) {
            int closet;
            if(i == 0) {
                closet = i + 1;
            } else {
                closet = (nums[i] - nums[i-1] <= nums[i + 1] - nums[i]) ? i - 1 : i + 1;
            }
            forward[i + 1] = (closet > i ? 1 : nums[i + 1] - nums[i]) + forward[i]; 
        }

        for(int i = n - 1; i > 0; i--) {
            int closet;
            if(i == n -1) {
                closet = i - 1;
            } else {
                closet = (nums[i] - nums[i-1] <= nums[i + 1] - nums[i]) ? i - 1 : i + 1;
            }
            backward[i - 1] = (closet < i ? 1 : nums[i] - nums[i - 1]) + backward[i];
        } 

        vector<int> res;

        for(auto &q : queries) {
            int l = q[0], r = q[1];
            int val = (l > r ? backward[r] - backward[l] : forward[r] - forward[l]);
            res.push_back(val); 
        }

        return res;
    }
};