// Last updated: 7/23/2026, 3:56:42 PM
1class Solution {
2public:
3    int uniqueXorTriplets(vector<int>& nums) {
4        int pow2[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072};
5        int n = nums.size();
6
7        if(n == 2) return 2;
8        if(n == 1) return 1;
9        return *lower_bound(pow2, pow2 + 18, n + 1);
10    }
11};