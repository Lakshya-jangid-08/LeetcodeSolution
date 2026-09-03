// Last updated: 9/3/2026, 11:20:11 AM
1class Solution {
2public:
3    bool uniformArray(vector<int>& nums1) {
4        int minOdd = 1e8, mnv = 1e8;
5
6        for(auto &v : nums1) {
7            mnv = min(mnv, v);
8            if(v&1) minOdd = min(minOdd, v);
9        }
10
11        // even - odd => odd
12        // odd - odd => even
13        return (mnv & 1) ? true : (minOdd == 1e8);
14    }
15};