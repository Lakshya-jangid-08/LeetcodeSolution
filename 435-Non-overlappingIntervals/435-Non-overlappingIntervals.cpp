// Last updated: 4/4/2026, 11:36:49 am
1class Solution {
2    static const bool comp(vector<int>& a, vector<int>& b) {
3        return a[1] < b[1];
4    }
5public:
6    int eraseOverlapIntervals(vector<vector<int>>& nums) {
7        sort(nums.begin(), nums.end(), comp);
8        int cnt = 1;
9        int end = nums[0][1];
10        for(int i = 0; i < nums.size(); i++) { 
11            if(nums[i][0] >= end) {
12                end = nums[i][1];
13                cnt++;
14            }
15        }
16        return nums.size() - cnt;
17    }
18};