// Last updated: 6/29/2026, 10:19:21 AM
class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums;
        vector<int> res;
        res.push_back(nums[0]);
        vector<int> rightMax(n);
        rightMax[n-1] = nums[n-1];
        for(int i = n - 2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i+1], nums[i+1]);
        }
        int leftMax = nums[0];
        for(int i = 1; i < n-1; i++) {
            if(leftMax < nums[i] || rightMax[i] < nums[i]) {
                res.push_back(nums[i]);
            }
            leftMax = max(leftMax, nums[i]);
        }
        res.push_back(nums.back());
        return res;
    }
};