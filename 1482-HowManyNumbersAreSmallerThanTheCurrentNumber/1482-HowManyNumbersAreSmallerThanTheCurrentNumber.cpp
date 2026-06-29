// Last updated: 6/29/2026, 10:21:44 AM
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        vector<int>res(n);
        for(int i = 0; i < n; i++) {
            int cnt = 0;
            int val = nums[i];
            for(int j = 0; j < n; j++) {
                if(val > nums[j]) cnt++;
            }
            res[i] = cnt;
        }
        return res;
    }
};