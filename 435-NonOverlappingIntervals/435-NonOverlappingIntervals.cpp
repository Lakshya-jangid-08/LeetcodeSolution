// Last updated: 6/29/2026, 10:22:40 AM
class Solution {
    static const bool comp(vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& nums) {
        sort(nums.begin(), nums.end(), comp);
        int cnt = 1;
        int end = nums[0][1];
        for(int i = 0; i < nums.size(); i++) { 
            if(nums[i][0] >= end) {
                end = nums[i][1];
                cnt++;
            }
        }
        return nums.size() - cnt;
    }
};