// Last updated: 4/26/2026, 1:20:12 PM
1class Solution {
2public:
3    vector<int> getConcatenation(vector<int>& nums) {
4        int n = nums.size();
5        vector<int>res(2*n);
6        int i = 0;
7        for(auto val : nums) {
8            res[i] = val;
9            res[i + n] = val;
10            i++;
11        }
12        return res;
13    }
14};