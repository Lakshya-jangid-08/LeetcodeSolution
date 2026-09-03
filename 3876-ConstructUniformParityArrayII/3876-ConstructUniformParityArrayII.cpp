// Last updated: 9/3/2026, 11:16:24 AM
1class Solution {
2public:
3    bool uniformArray(vector<int>& nums1) {
4        int mnv = *min_element(nums1.begin(), nums1.end());
5        int minOdd = 1e8, minEven = 1e8;
6
7        for(auto &v : nums1) {
8            if(v&1) minOdd = min(minOdd, v);
9            else minEven = min(minEven, v);
10        }
11
12        // even - odd => odd
13        // odd - odd => even
14
15        int even = (mnv & 1) ? 0 : 1;
16        if(even) return (minOdd == 1e8);
17
18        return true;
19
20    }
21};