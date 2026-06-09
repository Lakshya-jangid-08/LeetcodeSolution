// Last updated: 6/9/2026, 10:18:06 AM
1class Solution {
2public:
3    long long maxTotalValue(vector<int>& nums, int k) {
4        long long maxElem = *max_element(nums.begin(), nums.end());
5        long long minElem = *min_element(nums.begin(), nums.end());
6    
7    
8        return 1LL * k * (maxElem - minElem);
9    }
10};