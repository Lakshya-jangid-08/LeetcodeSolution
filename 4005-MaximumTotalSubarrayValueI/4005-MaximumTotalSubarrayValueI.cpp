// Last updated: 6/29/2026, 10:20:12 AM
class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int maxElem = *max_element(nums.begin(), nums.end());
        int minElem = *min_element(nums.begin(), nums.end());
    
    
        return 1LL * k * (maxElem - minElem);
    }
};