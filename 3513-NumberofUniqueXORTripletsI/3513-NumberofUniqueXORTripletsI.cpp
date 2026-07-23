// Last updated: 7/23/2026, 4:06:47 PM
1class Solution {
2public:
3    int uniqueXorTriplets(vector<int>& nums) {
4        size_t n = nums.size();
5        int m = n;
6        
7        m |= m >> 1;
8        m |= m >> 2;
9        m |= m >> 4;
10        m |= m >> 8;
11        m |= m >> 16;
12        
13        return (m + 1) >> (3 / (n + 1));
14    }
15};