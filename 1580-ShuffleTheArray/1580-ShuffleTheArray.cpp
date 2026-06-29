// Last updated: 6/29/2026, 10:21:41 AM
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int>res (2*n);
        int j = 0;
        for(int i = 0; i < n; i++) {
            res[j] = nums[i];
            res[j+1] = nums[i + n];
            j+=2;
        }
        return res;
    }
};